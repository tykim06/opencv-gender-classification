# opencv_gender_classification


rasberrypi install

https://blog.iwanhae.ga/pi-opencv-cmake/

pi cam enable

sudo modprobe bcm2835-v4l2

No module named cv

sudo apt-get install python-opencv

crop face

https://github.com/wavexx/facedetect

sudo apt-get install imagemagick

for file in path/to/pictures/*.jpg; do
  name=$(basename "$file")
  i=0
  facedetect "$file" | while read x y w h; do
    convert "$file" -crop ${w}x${h}+${x}+${y} "path/to/faces/${name%.*}_${i}.${name##*.}"
    i=$(($i+1))
  done
done
