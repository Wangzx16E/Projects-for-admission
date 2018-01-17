# -*- coding:utf-8 -*-

import InitClient
from pymongo import MongoClient

APP_KEY = '2184924406'
APP_SECRET = '864b26c20ecc891b460b3e73c8693936'
CALL_BACK = 'http://api.weibo.com/oauth2/default.html'
ACCESS_TOKEN = '2.00BxdyEGOeir4C36b11ec21e0qYUL2'
def run():

    client = InitClient.get_client(APP_KEY, APP_SECRET, CALL_BACK, ACCESS_TOKEN)
    while True:


        statuses = client.statuses__bilateral_timeline()['statuses']
        length = len(statuses)

        print length

        Monclient = MongoClient('localhost', 27017)
        db = Monclient['Weibo']

        WeiboData = db['test1']

        for i in range(0, length):
            created_at = statuses[i]['created_at']
            id = statuses[i]['user']['id']
            province = statuses[i]['user']['province']
            city = statuses[i]['user']['city']
            followers_count = statuses[i]['user']['followers_count']
            friends_count = statuses[i]['user']['friends_count']
            statuses_count = statuses[i]['user']['statuses_count']
            url = statuses[i]['user']['url']
            geo = statuses[i]['geo']
            comments_count = statuses[i]['comments_count']
            reposts_count = statuses[i]['reposts_count']
            nickname = statuses[i]['user']['screen_name']
            desc = statuses[i]['user']['description']
            location = statuses[i]['user']['location']
            text = statuses[i]['text']


            WeiboData.insert_one({
                'created_at': created_at,
                'id': id,
                'nickname': nickname,
#                'text': text,
                'province': province,
                'location': location,
#                'description': desc,
                'city': city,
#                'followers_count': followers_count,
#                'friends_count': friends_count,
#                'statuses_count': statuses_count,
#                'url': url,
                'geo': geo,
#                'comments_count': comments_count,
#                'reposts_count': reposts_count
                })

if __name__ == "__main__":
    run()