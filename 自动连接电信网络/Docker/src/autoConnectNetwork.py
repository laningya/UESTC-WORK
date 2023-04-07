import time
import os
import schedule
import requests as rq

strConfig = []

file = open("/code/config/config.txt","r")
while True:
    line = file.readline()
    if not line:
        break
    strConfig.append(line[line.find('\"')+1:line.rfind('\"')])
file.close()

post_url_ip = strConfig[0]
post_data_queryString = strConfig[1]
post_data_userId =  strConfig[2]
post_data_password = strConfig[3]

header = {
    "Accept": "*/*",
    "Accept-Encoding": "gzip, deflate",
    "Accept-Language": "en,ru;q=0.9,ja;q=0.8,zh-CN;q=0.7,zh;q=0.6,ko;q=0.5,zh-TW;q=0.4",
    "Connection": "keep-alive",
    "Content-Length": "580",
    "Content-Type": "application/x-www-form-urlencoded; charset=UTF-8",
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36",
}
post_data = {"userId": post_data_userId,
             "password": post_data_password,
             "queryString": post_data_queryString,
             "passwordEncrypt": "true"
             }
post_url = "http://" + post_url_ip + "/eportal/InterFace.do?method=login"


def login():
    z = rq.post(url=post_url, data=post_data, headers=header)
    print(z.content.decode("utf-8").split(",")[1])

schedule.every(1).minutes.do(login)

while True:
    schedule.run_pending()
    time.sleep(1)
