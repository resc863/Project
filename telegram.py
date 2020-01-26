from bs4 import BeautifulSoup
import requests, urllib

def search_book(keyword):
    base_url = 'https://www.aladin.co.kr/search/wsearchresult.aspx?'
    encoding_type = 'EUC-KR'
    book_list = []
    params = {'SearchTarget':'DVD','SortOrder':11}
    params['SearchWord'] = keyword

    url =  base_url + urllib.parse.urlencode(params, encoding = encoding_type)
    url_get = requests.get(url)
    soup = BeautifulSoup(url_get.content, 'lxml')
    items = soup.find_all(class_='ss_book_box')
    list = []

    for item in items:
        if item.find(class_='ss_book_list') is None:
            continue
        name = item.find(class_="bo3").string
        info = {}
        info['name']=name

        data1 = item.find(class_="ss_book_list").find_next('ul').find_all('li')[1].find_all('a')
        data = ""

        try:
            price = item.find(class_="ss_book_list").find_next('ul').find_all('li')[2].find('span').string
            info['price'] = price
        except:
            info['price'] = 'None'
        
        for i in data1:
            data = data + i.string

        info['data']=data

        list.append(info)
    return list

url = 'http://www.yes24.com/Product/Goods/84907426?scode=032&OzSrank=13'
html = requests.get(url).text

soup = BeautifulSoup(html, 'html.parser')

print("Yes24 정보\n")

book_name = '#yDetailTopWrap > div.topColRgt > div.gd_infoTop > div > h2'
book = soup.select(book_name)
print("타이틀명: "+book[0].text+"\n")

release_date = '#yDetailTopWrap > div.topColRgt > div.gd_infoTop > span.gd_pubArea > span'
release = soup.select(release_date)

for i in release:
    date = i.get('class')

    for j in date:
        if j == 'gd_date':
            print("출시일 : "+i.text+"\n")

rating = '#yDetailTopWrap > div.topColRgt > div.gd_infoTop > span.gd_ratingArea > span'
rating1 = soup.select(rating)
print("평가: "+rating1[0].text)

price_info = '#yDetailTopWrap > div.topColRgt > div.gd_infoBot > div.gd_infoTbArea > div:nth-child(3) > table > tbody > tr:nth-child(1) > td > span > em'
price = soup.select(price_info)
print("정가: "+price[0].text+"\n")

sale_price = '#yDetailTopWrap > div.topColRgt > div.gd_infoBot > div.gd_infoTbArea > div:nth-child(3) > table > tbody > tr.accentRow > td > span > em'
sale = soup.select(sale_price)
print("할인가: " +sale[0].text)

print("\n\n")


url = 'https://www.aladin.co.kr/search/wsearchresult.aspx?SearchTarget=DVD&KeyWord=%B0%DC%BF%EF%BF%D5%B1%B9+2&KeyRecentPublish=0&OutStock=0&ViewType=Detail&CustReviewCount=0&CustReviewRank=0&KeyFullWord=%B0%DC%BF%EF%BF%D5%B1%B9+2&KeyLastWord=%B0%DC%BF%EF%BF%D5%B1%B9+2&CategorySearch=&chkKeyTitle=&chkKeyAuthor=&chkKeyPublisher=&chkKeyISBN=&chkKeyTag=&chkKeyTOC=&chkKeySubject='
html = requests.get(url).text

soup = BeautifulSoup(html, 'html.parser')

print("알라딘 정보\n")

dvdlist = search_book('겨울왕국2')

for i in dvdlist:
    print("타이틀명: "+i['name']+"\n")
    print("가격: "+i['price']+"\n")
    print("정보: "+i['data']+"\n")
    print("\n\n")
