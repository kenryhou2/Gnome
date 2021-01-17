# Gnome
## Your Personal Garden Guardian

## Inspiration
Quarantine has recently made a lot of us plant moms and plant dads. Although that's wonderful for us humans, that's not what the heat waves in LA or backyard critters tell us! Gnome is a device that will notify you of any intruders or environmental conditions of your plants, like a garden guardian!

## What it does
Gnome is continually sensing, broadcasting data, and running classifiers about your plants in real time. These include conditions of soil moisture, ambient light and even motion sensing for any unwanted critters. Then, if critical conditions are met, it will warn you about potential situations that might put your plants in danger. Also, it is interfaced by a remote GUI from your laptop where you can check the live conditions of your garden including sensor info and a live video feed from anywhere in your household!

## How I built it
TI Kit Hardware: TI Launchpad (Multithreaded MSP432), TI boosterpacks (Grove Sensors, CC3100 Wifi Booster), Webcam Software: Energia (C++), MQTT and TKinter/GUI (Python), Powershell (pkg scripts)

## Challenges
- Interfacing the hardware with the wifi, working on multithreaded hardware applications/timing
- Real time results 
## Accomplishments that we're proud of Communications between hardware and GUI!
- Packaging a product, end to end communications

## What's next for Gnome
Slimmer packaging, more intuitive UI, additional sensors, image processing, machine learning and more!
