#coding=utf-8

import requests
import json
from collections import Iterable, Iterator
##############################################
#######可迭代对象和迭代器对象的实现###########

#迭代器的抽象接口
#Iterator.__abstractmethods__
#frozenset({'next'})

#可迭代对象的抽象接口
#Iterable.__abstractmethods__
#frozenset({'__iter__'})

class WeatherIterator(Iterator):
	#构造器
	#cities为城市的列表
	def __init__(self, cities):
		self.cities = cities
		self.index = 0
	
	def getWeather(self, city):
		r= requests.get(u'http://wthrcdn.etouch.cn/weather_mini?city=' + city)
		data = r.json()['data']['forecast'][0]
		return '%s: %s , %s ' % (city, data['low'], data['high'])

	def next(self):
		#所有城市都迭代完了
		if self.index == len(self.cities):
			raise StopIteration
		city = self.cities[self.index]
		self.index += 1
		return self.getWeather(city)

class WeatherIterable(Iterable):
	def __init__(self, cities):
		#维护cities，以便传给迭代器
		self.cities = cities

	def __iter__(self):
		return WeatherIterator(self.cities)
#print getWeather(u'北京')
#print getWeather(u'长沙')

for x in WeatherIterable([u'北京', u'上海', u'广州', u'长春']):
	print x
###############################################
