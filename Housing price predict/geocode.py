
# -*- coding: utf-8 -*-

#ak='ES6rNQQGhsxM2U9DwiNWAGGynSIBpKAs'
import urllib2, urllib
from pymongo import MongoClient
import json


import requests


MongoClient = MongoClient('localhost', 27017)
db = MongoClient['Weibo']

cursor = db.test.find()
for status in cursor:
    _id = status['_id']
    geo = status['geo']
    coordinates = geo['coordinates']

    loc = json.dumps(coordinates)

    payload = {'callback':'renderReverse','location':loc[1:-1],'coordtype':'wgs84II','output':'json','ak':'ES6rNQQGhsxM2U9DwiNWAGGynSIBpKAs','callback': 'renderReverse'}


    r = requests.get("http://api.map.baidu.com/geocoder/v2/", params=payload)
    

    content = urllib2.urlopen(r.url).read()

    print(content)
    
   


#    WeiboData = db['test']
#    WeiboData.insert_one({
#        'geocode_zh': geocode_zh,
#        'formatted_address': formatted_address,
#        'province': province,
#        'city': city,
#        'district': district,
#        'adcode': adcode,
#        'street': street,
#        'street_number': street_number,
#        'direction': direction,
#        'distance': distance,
#        'sematic_description': sematic_description,
#        'poiRegions': poiRegions
#        })

   
 

    




