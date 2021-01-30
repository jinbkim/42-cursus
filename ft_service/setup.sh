minikube start --driver=virtualbox
eval $(minikube -p minikube docker-env)

# metallb
echo "metalLB manifest"
minikube addons enable metallb
kubectl apply -f ./srcs/metallb/config.yaml

# nginx
cd ./srcs/nginx
echo "nginx image build"
docker build -t nginx:latest .
echo "nginx deployment"
kubectl apply -f nginx.yaml

# ftps
cd ../ftps
echo "ftps image build"
docker build -t ftps:latest .
echo "ftps deployment"
kubectl apply -f ftps.yaml

# mysql
cd ../mysql
echo "mysql image build"
docker build -t mysql:latest .
echo "mysql deployment"
kubectl apply -f mysql.yaml

# phpmyadmin
cd ../phpmyadmin
echo "phpmyadmin image build"
docker build -t phpmyadmin:latest .
echo "phpmyadmin deployment"
kubectl apply -f phpmyadmin.yaml

# wordpress
cd ../wordpress
echo "wordpress image build"
docker build -t wordpress:latest .
echo "wordpress deployment"
kubectl apply -f wordpress.yaml

#influxdb
cd ../influxdb
echo "influxdb image build"
docker build -t influxdb:latest .
echo "influxdb deployment"
kubectl apply -f influxdb.yaml

# telegraf
cd ../telegraf
echo "telegraf image build"
docker build -t telegraf:latest .
echo "telegraf deployment"
kubectl apply -f telegraf.yaml

# grafana
cd ../grafana
echo "grafana image build"
docker build -t grafana:latest .
echo "grafana deployment"
kubectl apply -f grafana.yaml
