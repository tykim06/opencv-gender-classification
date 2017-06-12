# opencv_gender_classification


## OS

+ Ubuntu 14.04

## OpenCV

+ 2.4.13
+ install : http://webnautes.tistory.com/557
+ install arm board : http://ausome.tistory.com/4
  + output : opencv/

## Data Set

+ 1,300 picture  ==>  gender_at.yml

## Cropping Picture

+ create_csv.py
+ crop_face.py
+ facedetect : https://github.com/wavexx/facedetect
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
## Result

![Alt text](https://user-images.githubusercontent.com/16299919/27033032-6ed79c32-4fb2-11e7-813a-11df51cf0163.png)
