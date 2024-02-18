import os,sys,shutil
from distutils.core import setup, Extension
from Cython.Build import cythonize

for main_file in ["blade.cpp", "menu.cpp"]:
	try:
		nama = main_file.split(".")[0]
		setup( name = main_file, ext_modules = cythonize(Extension(name=nama, sources=[main_file])), script_args = ["build_ext", "--inplace", "--force", "-j 5"])
	except Exception as e: pass
	
	if os.path.exists(main_file):
		try: shutil.rmtree("build/")
		except: 0
	else:
		os.system("pip install -r requirements.txt")
		os.system("python build.py")
		
for main_file in ["blade.cpp", "menu.cpp"]:
	try: os.remove(main_file)
	except: 0
