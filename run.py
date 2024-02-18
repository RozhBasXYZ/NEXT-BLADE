import os, blade as rozhbasxyz

try:
	os.system("git pull")
	os.system("python build.py")
except:
	print("[!] anda memakai versi terbaru")

if __name__ == "__main__": rozhbasxyz.menu_login()
