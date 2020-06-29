## 1 - Introduction

The Yoga Pose recognition algorithm described in this example is intended for wearable devices, since all the data logs have been acquired with the device placed on the left leg, with the orientation described in section 2. Fourteen different classes are recognized, as described in section 3.

The Machine Learning Core is configured to run at 104 Hz, features are extracted on windows of 52 samples, therefore the Decision Tree classifier output is updated two times per second.

Three different features are computed from accelerometer and gyroscope data:

- Mean on accelerometer X/Y/Z axes
- Variance on the gyroscope X/Y/Z axes
- Energy on the gyroscope squared norm


## 2 - Device orientation

The [SensorTile.Box](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mems-motion-sensor-eval-boards/steval-mksbox1v1.html) is placed on the left leg (see picture below). Other devices can be used as well, provided that the orientation of sensor axes is correct.

- X axis parallel to the leg, pointing up.
- Y axis perpendicular to the leg, pointing to the inside.
- Z axis pointing forward.

![SensorTileBoxOnLeftLeg](.\SensorTileBoxOnLeftLeg.jpg)

*Source of images: Wikipedia. [Front view](https://commons.wikimedia.org/wiki/File:Tadasana_Yoga-Asana_Nina-Mel.jpg) and [Side view](https://commons.wikimedia.org/wiki/File:Chaturanga-Dandasana_low_Yoga-Asana_Nina-Mel.jpg).*


## 3 - Decision Tree output values

The Decision Tree classifiers detects 14 different classes corresponding to 12 different Yoga positions (see picture below) and 2 Non-Yoga position (Standing still and in motion). The output of the Decision Tree classifier is stored in the register MLC0_SRC (address 70h).

This is the list of values that the MLC0_SRC register can have and the corresponding class label:

- 0 = Boat Pose
- 1 = Bow Pose
- 2 = Bridge
- 3 = Child's Pose
- 4 = Cobra's Pose
- 5 = Downward-Facing Dog
- 6 = Meditation Pose
- 7 = Plank
- 8 = Seated Forward Bend
- 9 = Standing in Motion
- 10 = Standing Still
- 11 = The Extended Side Angle
- 12 = The Tree
- 13 =  Upward Plank

![SensorTileBoxYogaPoses](.\SensorTileBoxYogaPoses.jpg)

*Source of images: Wikipedia and Pixabay. [Boat Pose](https://en.wikipedia.org/wiki/File:Paripurna-Navasana_Yoga-Asana_Nina-Mel.jpg), [Bow Pose](https://commons.wikimedia.org/wiki/File:Tadasana_Yoga-Asana_Nina-Mel.jpg), [Bridge](https://commons.wikimedia.org/wiki/File:Setubandhasana_oblique_view.JPG), [Child's Pose](https://pixabay.com/it/photos/yoga-childs-posa-asana-2959214/), [Cobra Pose](https://commons.wikimedia.org/wiki/File:Bhujangasana_Yoga-Asana_Nina-Mel.jpg), [Downward-Facing Dog,](https://commons.wikimedia.org/wiki/File:Downward-Facing-Dog.JPG) [Meditation Pose](https://commons.wikimedia.org/wiki/File:Siddhasana_mulher.jpg), [Plank](https://commons.wikimedia.org/wiki/File:Chaturanga-Dandasana_low_Yoga-Asana_Nina-Mel.jpg), [Seated Forward Bend](https://commons.wikimedia.org/wiki/File:Janusirsasana_Yoga-Asana_Nina-Mel.jpg), [The Extended Side Angle](https://upload.wikimedia.org/wikipedia/commons/b/b5/Utthita-Parshvakonasana_Yoga-Asana_Nina-Mel.jpg), [The Tree](https://pl.m.wikipedia.org/wiki/Plik:Vriksasana_Yoga-Asana_Nina-Mel.jpg), [Upward Planck](https://commons.wikimedia.org/wiki/File:Putvottanasana_-_Upward_Plank_Pose_1_-_Diagonal_View.jpg), [Standing in Motion and Standing Still](https://commons.wikimedia.org/wiki/File:Tadasana_Yoga-Asana_Nina-Mel.jpg).*


## 4 - Interrupts

Whenever the Decision Tree output is updated (MLC0_SRC register at address 70h), an interrupt is generated (pulse on INT1 pin), that is two times per second in this example configuration. 

------

**More Information: [http://www.st.com](http://st.com/MEMS)**

**Copyright © 2020 STMicroelectronics**