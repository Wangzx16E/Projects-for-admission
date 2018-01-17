from pymongo import MongoClient
import re

d = {}
with open("/Users/wangzhixuan/Desktop/result") as f:
    for line in f:
        strline = ','.join(line)
        line = list(strline)
        result = re.split(',', line)



        print(result)
    