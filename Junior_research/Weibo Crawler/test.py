# -*- coding:utf-8 -*-

import InitClient
#from pymongo import MongoClient

APP_KEY = '2895178051'
APP_SECRET = 'ab4144adaa57560293663d278fe39d50'
CALL_BACK = 'http://api.weibo.com/oauth2/default.html'
ACCESS_TOKEN = '2.00BxdyEGLEsvJD93a867fd4eDgYkCB'

client = InitClient.get_client(APP_KEY, APP_SECRET, CALL_BACK, ACCESS_TOKEN)
while True:


    statuses = client.statuses__bilateral_timeline()['statuses']
    #length = len(statuses)

    print(statuses)

