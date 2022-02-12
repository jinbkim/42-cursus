FROM debian:buster

RUN apt-get update

RUN apt-get -y install vim wget nginx php-fpm php-mysql php-mysqlnd php-mbstring mariadb-client mariadb-server

COPY ./srcs/default /etc/nginx/sites-available/default

COPY ./srcs/key /key

WORKDIR /var/www/html

RUN	wget https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-all-languages.tar.gz;\
	tar -xvf phpMyAdmin-4.9.5-all-languages.tar.gz;\
	rm -rf phpMyAdmin-4.9.5-all-languages.tar.gz;\
	mv phpMyAdmin-4.9.5-all-languages phpMyAdmin;

COPY ./srcs/config.inc.php /var/www/html/phpMyAdmin

RUN wget https://wordpress.org/latest.tar.gz;\
	tar -xvf latest.tar.gz;\
	rm -rf latest.tar.gz;

COPY ./srcs/wp-config.php /var/www/html/wordpress

RUN chown -R www-data:www-data *

RUN chmod 755 -R *

CMD	nginx -t;\
	service nginx start;\
	service mysql start;\
	service php7.3-fpm start;\
	echo "CREATE USER 'admin'@'%' identified by '1234';" | mysql -u root --skip-password;\
	echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password;\
	echo "GRANT ALL PRIVILEGES ON *.* TO 'admin'@'%';" | mysql -u root --skip-password ;\
	echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password;\
	sleep inf