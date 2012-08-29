import flickrapi
import xml
import urllib2
import os
import sys
import commands

api_key = 'e8d871060954aa0ac84850495fb11d5c'
url_base="http://www.flickr.com/photos/"
output_base="income/"
keyword_file="keyword.txt"

h_keyword_file=open(keyword_file)
keyword_list=h_keyword_file.readlines()

for i in range(0,len(keyword_list)) :
   keyword_list[i]=keyword_list[i].strip()
   print keyword_list[i]

print keyword_list
#os.system('pause')

#c = sys.stdin.readlines()

flickr = flickrapi.FlickrAPI(api_key,format='etree')
count=0

os.system("rm "+output_base+"tag/*");
os.system("rm "+output_base+"photo/*");

for keyword in keyword_list :
   photos = flickr.photos_search(text=keyword, per_page='100', page=10)
   listp=photos.find('photos').findall('photo')
   for i in range(0,len(listp)) :
    #  print listp[i].attrib['owner']
    #  print listp[i].attrib['id']
    #  print listp[i].attrib['server']
    #  print listp[i].attrib['title']
    #  print listp[i].attrib['farm']
    #  print listp[i].attrib['secret']
      photo_info=flickr.photos_getInfo(photo_id=listp[i].attrib['id'],secret=listp[i].attrib['secret'])
      tag_list=photo_info.find('photo').find('tags').findall('tag')
      tag_file_name=output_base+"tag/"+str(count)+".txt"
      photo_file_name=output_base+"photo/"+str(count)+".jpg"
      h_tag_file=open(tag_file_name,'w');
      for j in range(0,len(tag_list)) :
         isAsc=True
         for k in range(0,len(tag_list[j].text)):
            if(ord(tag_list[j].text[k])>127):
               isAsc=False
         if(isAsc):
            print tag_list[j].text
            h_tag_file.write(tag_list[j].text+"\n")
      h_tag_file.close()
      url_cur=url_base+listp[i].attrib['owner']+'/'+listp[i].attrib['id']
      url_cur="http://farm"+listp[i].attrib['farm']+".staticflickr.com/"+listp[i].attrib['server']+"/"+listp[i].attrib['id']+"_"+listp[i].attrib['secret']+".jpg"
     # print url_cur
      url_src = urllib2.urlopen(url_cur)
      outputfile = open(photo_file_name,'wb')
      outputfile.write(url_src.read())
      outputfile.close()
      count+=1

print vars(photos)

#sets = flickr.photosets_getList(api_key=api_key,text='cat')
 
