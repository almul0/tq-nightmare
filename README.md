# tq-nightmare
An openframeworks wiimote enabled scape room

## OpenFrameworks installation
### Under Linux
If you are using debian testing you have to download the nightly build package for your architecture from openframeworks website.

We are using gcc6.

Extract to /opt/openframeworks

Follow the guide they provide (debian|ubuntu as example):
```sh
cd /opt/openframeworks/scripts/linux/debian
./install_codecs.sh
./install_dependencies.sh
```
You can download a set of precompiled libraries from http://ci.openframeworks.cc/libs/ but it doesn't work for us.
For the nightly build you have to clone apothecary repository into libs directory and execute ./apothecary update poco
For us to compile poco with latest debian (buster), we need to update the GIT_TAG in apothecary/formulas/poco/poco.sh to 1.7.9

```sh
cd ..
./compileOF.sh
./compilePG.sh
```
## CLion IDE
This project is developed under Linux using CLion, althoug compilation under Windows may be possible using CLion or VisualStudio 2015.

If your openframeworks version is not 0.9.8 or nightly build dated on 20170714, make sure all dependencies and paths are correct and satisfied.

We are using a modified version of https://github.com/BildPeter/ofxCMake to build with CLion: https://github.com/almul0/ofxCMake

The steps are exactly the same, just some tweaks to get it working with Linux.

## Setup (TODO)

This project aims to stream over UDP a video buffer from an openframeworks application with a 3072x768 pixels resolution. This stream will be consumed by three raspberry pi piwall enabled and projected into three projector screens disposed as an open cube.

The interaction will be made using a WiiMote acting as a flashlight to reveal the scenario, with interactive actions inside.
