# wjdalstn.me 
정민수 작성
블로그 소스입니다.

##서버 설치법

**디지털오션** [https://www.digitalocean.com/](https://www.digitalocean.com/)에서 월 $5.00 에 서버를 구입한다.
**가비아** [https://www.gabia.com/](https://www.gabia.com/)에서 도메인을 구입한 후 가비아의 네임플러스를 사용해서 서버의 어아피를 도메인에 등록한다.

서버에 접속한 후 

```bash
$ ssh root@ip
# apt-get update && apt-get upgrade -y
# apt-get install gcc g++ vim git

```
##서버에 아파치(Apache2) 설정하기

```bash
# apt-get install apache2 -y
# cd /etc/apache2/sites-enabled
# sudo vim 000-default.conf

```

 1.***ServerName*** 에 자신의 ip주소를 넣는다.
 2.***ServerAdmin***에 자신의 E-mail을 넣는다.
 3.***DocumentRoot /var/www/cgi-bin/ ***으로 수정후 아래를 삽입 후 :wq 
 
 

 ```bash
 ScriptAlias /cgi-bin/ /var/www/cgi-bin/
	<Directory "/var/www/cgi-bin">
                AllowOverride None
                Options  +ExecCGI -MultiViews +SymLinksIfOwnerMatch
                AddHandler cgi-script .cgi .pl
                Order allow,deny
                Allow from all
	</Directory>
 
 ```
 
 ```bash
 # cd
 # vim apache2.conf
 ```
 에서 
 
 1.주석 처리된 ***ServerRoot*** 를 주석 해제
 2.***Directory /var/www/*** 부분을 다음과 같이 수정
 
 ```bash
 <Directory /var/www/cgi-bin/>
         Options FollowSymLinks ExecCGI MultiViews
         AddHandler cgi-script .cgi .pl
         AllowOverride None
         Require all granted
</Directory>
 ```
 
 페이지의 마지막에 ***ServerName http://localhost*** 를 입력 후 :wq
 
 ```bash
 # a2enmod cgi
 # Service apache2 restart
 ```
 
 하면 끝!
 
###서버에서 CGI for C 사용하기

cfc의 *path*가 ***/var/www/wjdalstn.me/***로 설정되어 있기 때문에 git에서 cfc를 다운받아 사용하는 사용자라면 파일을 모든 소스의 *path*를 원하는 *dir*로 변경하거나 실제로 ***/var/www/wjdalstn.me/***를 생성하여 사용하여야 한다.