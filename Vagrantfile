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
    echo "Installing the build essentials and git..."
    apt-get install -y build-essential git
    echo "Installing the Boost libraries..."
    apt-get install -y libboost-all-dev
    echo "Installing optional Snap dependencies"
    apt-get install -y gnuplot graphviz
    echo "Installing unzip"
    apt-get install unzip

    wget http://snap.stanford.edu/releases/Snap-3.0.zip
    unzip Snap-3.0.zip
    cd /vagrant/Snap-3.0
    make all
    cd examples
    git clone https://github.com/jorgeavaldez/eensim.git

  SHELL
end
