import os
import subprocess
import datetime
import requests

REPO_PATH = os.path.expanduser("~/Desktop/Code/learning-log")
DEEPSEEK_API_KEY = ""
env_path = os.path.join(REPO_PATH, ".env")
if os.path.exists(env_path):
    with open(env_path, "r", encoding="utf-8") as f:
        for line in f:
            if "DEEPSEEK_API_KEY" in line:
                DEEPSEEK_API_KEY = line.strip().split("=")[1]

def read_file(filename):
    path = os.path.join(REPO_PATH, filename)
    if os.path.exists(path):
        with open(path, "r", encoding="utf-8") as f:
            return f.read()
    return ""

def write_file(filename, content, mode="w"):
    path = os.path.join(REPO_PATH, filename)
    with open(path, mode, encoding="utf-8") as f:
        f.write(content)

def get_ai_diagnosis(today):
    if not DEEPSEEK_API_KEY:
        print("❌ 找不到 API Key！请检查根目录 .env 文件是否正确填写。")
        return None
    progress = read_file("progress.md")
    weakpoints = read_file("weakpoints.md")
    log = read_file("learning-log.md")
    feedback = read_file("feedback.md")
    
    prompt = f"""
    你是一个私人编程教练。今天是 {today}。
    这是我的当前状态：
    【进度】: {progress}
    【薄弱点】: {weakpoints}
    【历史日志】: {log[-800:]}
    【我的留言】: {feedback}
    
    请根据以下规则进行诊断并生成今日计划：
    1. 如果有卡壳/薄弱点，必须安排 20 分钟专项复习。如果连续卡壳，放慢速度，拆解任务。
    2. 输出格式必须严格按以下 Markdown 结构：
    
    # 📝 {today} 学习打卡
    ## 🧠 教练诊断
    （分析我的状态，指出今天该干什么）
    
    ## 📖 今日核心知识（生活化解释）
    1. [知识点1]
    2. [知识点2]
    3. [知识点3]
    
    ## 💻 今日实战任务（必须手写，禁止AI代写）
    （给我出一道代码题，并给出要求）
    
    ## ⭐ 自评分（1-5分）
    > 请在提交前在这里打分：_
    """

    headers = {"Authorization": f"Bearer {DEEPSEEK_API_KEY}", "Content-Type": "application/json"}
    data = {"model": "deepseek-chat", "messages": [{"role": "user", "content": prompt}]}
    
    print("🤖 正在呼叫 AI 大脑进行诊断，请稍候...")
    try:
        res = requests.post("https://api.deepseek.com/chat/completions", headers=headers, json=data, timeout=30)
        if res.status_code == 200:
            return res.json()['choices'][0]['message']['content']
        else:
            print(f"❌ API 请求失败，错误码: {res.status_code}, 信息: {res.text}")
            return None
    except Exception as e:
        print(f"❌ 网络出错: {e}")
        return None

def auto_git_push(today):
    os.chdir(REPO_PATH)
    print("🚀 正在同步到 GitHub...")
    subprocess.run(["git", "pull", "--rebase"], capture_output=True)
    subprocess.run(["git", "add", "."])
    subprocess.run(["git", "commit", "-m", f"auto: {today} 智能打卡"])
    result = subprocess.run(["git", "push"], capture_output=True, text=True)
    if result.returncode == 0:
        print("✅ GitHub 同步成功！")
    else:
        print(f"⚠️ 推送遇到问题: {result.stderr}")

def main():
    today = datetime.date.today().strftime("%Y-%m-%d")
    ai_content = get_ai_diagnosis(today)
    if ai_content:
        note_file = f"notes/{today}.md"
        write_file(note_file, ai_content)
        print(f"✅ 已成功生成今日笔记: {note_file}")
        write_file("learning-log.md", f"- {today}: AI 引擎自动生成计划。\n", mode="a")
        auto_git_push(today)

if __name__ == "__main__":
    main()
