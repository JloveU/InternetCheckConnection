#InternetCheckConnection
---

本程序为Windowes平台的控制台程序，利用Windows API中的[InternetCheckConnection][1]函数，检测当前是否联通互联网。

##使用说明：

|命令                              | 动作                                         |
|:---------------------------------|:---------------------------------------------|
|InternetCheckConnection /?        | 查看帮助信息                                 |
|InternetCheckConnection           | 检测是否可连接到网络，可连接返回1，否则返回0 |
|InternetCheckConnection time n    | 检测是否可连接到网络，可连接返回1，否则每隔time毫秒检测1次，最多检测n次 |

##版本更新

###V1.0
2014-08-15
最初版本，通过访问百度（<http://www.baidu.com/>）来检测是否可联网。

###V1.1
2014-08-19
只根据能否访问百度这一个网站的话，会有一个问题，如果某天百度抽风了访问不了，但是其他网站可以访问，那么就会错误判断为未联网。
因此，此版本依次访问百度（<http://www.baidu.com/>）、淘宝（<http://www.taobao.com/>）和腾讯（<http://www.qq.com/>），当这三个网站均不可访问时判断为未联网。
另外，加入了图标，并设置了版本信息。


[1]: http://msdn.microsoft.com/en-us/library/aa384346(VS.85).aspx "InternetCheckConnection function (Windows) - MSDN"

