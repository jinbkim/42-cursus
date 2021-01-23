# chown -R www-data /var/www/*
chmod -R 755 /var/www/*

mkdir -p /var/www/html
touch /var/www/html/index.php
echo "<?php phpinfo(); ?>" >> /var/www/html/index.php


mkdir -p /etc/nginx/sites-available/
mkdir -p /etc/nginx/sites-enabled/
# mv /usr/sbin/default.conf /etc/nginx/sites-available/default
# ln -s /etc/nginx/sites-available/default /etc/nginx/sites-enabled/default

# chown -R www-data:www-data /var/www/html/wordpress

# service nginx start
# /etc/init.d/nginx start
# service php7.3-fpm start
# tail -f /dev/null

mysql -hmysql -Dwordpress -uuser -ppass < /run/nginx/wordpress.sql
