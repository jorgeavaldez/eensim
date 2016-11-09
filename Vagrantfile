# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
  config.vm.box = "ubuntu/trusty64"

  config.vm.provider "virtualbox" do |v|
    v.memory = 2048
    v.cpus = 2
  end

  config.vm.provision "shell", inline: <<-SHELL
    cd /vagrant
    mkdir bin
    mkdir obj
    apt-get update
    apt-get upgrade
    echo "Installing the stuff..."
    apt-get install -y build-essential git libboost-all-dev gnuplot graphviz unzip
    cd /
    wget https://github.com/dacoconuttman/snap/archive/master.zip
    mv master.zip Snap-3.0.zip
    unzip Snap-3.0.zip
    cd /Snap-3.0
    make all
    cd /vagrant

  SHELL
end
