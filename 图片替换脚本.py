import re
import requests
def parseText(textpath):
    f = open(textpath,'r+',encoding = 'utf-8')
    text = str(f.read())
    f.close()
    return text

def getPicPath(text):
    srcPic = re.findall(r'\!\[\d*\]\(.*\)',text)
    dst = []
    for i in srcPic:
        str1 = re.findall('\(.*\)',i)[0]
        str1 = str1[1:-1]
        dst.append(str1)
    return srcPic,dst

def getPicUrl(rootpath,dst):
    Piclst = []
    upUrl = 'https://sm.ms/api/upload'
    for i in dst:
        path = rootpath+i
        data = {'smfile':open(path,'rb')}
        r = requests.post(upUrl,files=data)
        m = (str(r.text))
        m = eval(m)
        storename = m['data']['storename']
        url = m['data']['url']
        aurl = ''
        for i in url:
            if(i=='\\'):
                continue
            else:
                aurl+=i
        url = aurl
        Piclst.append({'storename':storename,'url':url})
    cmp = []
    for i in Piclst:
        name = i['storename']
        url = i['url']
        a = '!['+name+']'+'('+url+')'
        cmp.append(a)
    return cmp

def textReplace(text,src,dst):
    for i in range(len(src)):
        text =text.replace(src[i],dst[i])
    return text

def rewrite(textpath,text):
    f = open(textpath,'w+',encoding='utf-8')
    f.write(text)
    f.close()

def main():
    rootpath = 'your_markdown_filepath'
    textpath = rootpath+'your_markdown_filename'
    text = parseText(textpath)
    src,picdst = getPicPath(text)
    cmp = getPicUrl(rootpath,picdst)
    text = textReplace(text,src,cmp)
    rewrite(textpath,text)

main()
