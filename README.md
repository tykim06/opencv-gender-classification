# opencv_gender_classification


## OS

+ Ubuntu 14.04

## OpenCV

+ 2.4.13

## Data Set

+ 1,300 picture  ==>  gender_at.yml

## Cropping Picture

+ https://github.com/wavexx/facedetect

+ sudo apt-get install imagemagick

    ```
    for file in path/to/pictures/*.jpg; do
      name=$(basename "$file")
      i=0
      facedetect "$file" | while read x y w h; do
        convert "$file" -crop ${w}x${h}+${x}+${y} "path/to/faces/${name%.*}_${i}.${name##*.}"
        i=$(($i+1))
      done
    done
    ```
