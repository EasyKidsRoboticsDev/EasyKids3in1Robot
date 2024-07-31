# **Arduino Library For 3in1EasyKids Robot Kit**
## **Introduction**
#### ชุดหุ่นยนต์สอนเขียนโปรแกรม 3 ภาษาคอมพิวเตอร์ 3 ระดับ ในหุ่นยนต์ชุดเดียว

* Block-Based Programming
* Python
* C/C++

สนุกเข้าใจง่ายเพื่อฝึกทักษะการประดิษฐ์หุ่นยนต์ด้วยตัวเอง เรียนรู้การเขียนโปรแกรมควบคุมหุ่นยนต์เพื่อทำภารกิจต่าง ๆ เช่น การเคลื่อนที่ด้วยล้อ Mecanum การแสดงไฟ RGB การแสดงเสียงและดนตรี การหยิบจับวัตถุ การเคลื่อนย้ายวัตถุ การหลบหลีกวัตถุ การแสดงภาพบน LCD รวมถึงการควบคุมหุ่นยนต์ด้วยการสื่อสารแบบ WiFi/BT จากโทรศัพท์มือถือ ฯลฯ เรียนรู้แบบบูรณาการ STEAM (Science Technology Engineering Art Mathematic) เป็นการปูพื้นฐานความรู้ด้านวิทยาการคำนวณและหุ่นยนต์ เสริมสร้างความคิดสร้างสรรค์ การคิดวิเคราะห์อย่างเป็นระบบ เพื่อพัฒนาศักยภาพและฝึกทักษะการแก้ไขปัญหาอย่างมีเหตุผลให้แก่เยาวชน

[EasyKidsRobotics](https://www.easykidsrobotics.com/) สอนให้เยาวชนได้ลงมือทำ ทดลอง และแก้ไขปัญหาด้วยตัวเอง 
การให้เยาวชนได้เจอโจทย์และแก้ปัญหาบ่อย ๆ จะช่วยให้เกิดการพัฒนาตัวเอง สร้างความมั่นใจ ไม่กลัว และไม่หนีปัญหา เยาวชนจะสามารถแก้ปัญหาได้ รู้ที่มาที่ไป สาเหตุของปัญหา และคิดหาวิธีแก้ หากวิธีนี้ไม่สำเร็จ 
ก็เปลี่ยนวิธีใหม่ทักษะนี้สามารถประยุกต์ใช้กับชีวิตจริงของพวกเขาได้ ทำให้รู้สึกว่าทุกปัญหามีทางออก เป็นการสร้างพื้นฐานการคิดและจิตใจให้เข้มแข็ง มีความพยายามมากขึ้น ให้พวกเขาพร้อมต่อยอดไปได้ในทุก ๆ เรื่อง ไม่ว่าการเข้ามหาวิทยาลัย การทำงานในอนาคต หรือทำอะไรก็ตามในชีวิตของพวกเขา

![Poster(ENG) A4](https://github.com/user-attachments/assets/5eff91ec-96d2-4762-a5e2-3796d0f5d88d)

![Poster Back A4](https://github.com/user-attachments/assets/a1911f93-94a1-4c7d-984d-04546fb70ecf)


## **How to Install**

1. เพิ่มบอร์ด EasyKids3in1 ใน Arduino IDE 
1. เลือก Library EasyKids3in1 ใน Arduino IDE

## **การเพิ่มบอร์ด EasyKids3in1 ใน Arduino IDE**
(Windows OS) เลือกที่ File >>> preferences 

(Mac OS) เลือกที่ Arduino IDE >>> Settings... 
![268210068-dd8353f5-ace5-41e8-b70e-48a8405cdbff](https://github.com/user-attachments/assets/7d0522e5-8a8a-418a-9da4-225f2e83c7b4)

Package บอร์ด EasyKids3in1 

* Copy ลิ้งนี้ >>> : https://github.com/EasyKidsRoboticsDev/arduino-easykidsrobotics/releases/download/4.3.3/package_easykidsrobotics_index.json
  
![268210153-3b153bd6-6cb8-49cb-9bb9-1c09fb380ef0](https://github.com/user-attachments/assets/2514ba2f-4247-47b5-ac75-74ba090fcdce)


ใส่ลงในช่อง Additional boards managers URLS แล้วกด "OK"

![268382687-4b57629c-808c-43b6-97e4-3ff5ad9d3d06](https://github.com/user-attachments/assets/0f515bfe-95f6-4a6b-920e-f34f696a66cb)

จากนั้นกด "OK"

![268210285-65cb4395-d57a-4765-a880-a76cd3386108](https://github.com/user-attachments/assets/8fb7ae0c-161f-4b65-90d0-3c0a68f79a10)

จากนั้นเลือกไปที่ BOARDS MANAGER พิมพ์คำว่า EasyKidsRobotics ในช่องค้นหา และให้กดคลิ๊ก "INSTALL" เพื่อทำการติดตั้งและรอจนกว่าจะติดตั้งเสร็จสมบูรณ์

![268382607-c0286d9b-a1b0-4b04-ac25-38bc41f78094](https://github.com/user-attachments/assets/5881dd43-6b24-4955-9f92-69e5f3d2128d)

หลังจากที่ทำการโหลดและติดตั้งบอร์ด EasyKids3in1 เรียบร้อยแล้ว ต่อไปจะเป็นการเลือกบอร์ด โดยให้คลิ๊กไปที่ Tools >>> Board: >>> EasyKidsRobotics >>> และเลือกที่ EasyKids3in1 

![268382749-bc15603c-45dd-437b-84aa-6022edcc545e](https://github.com/user-attachments/assets/3f10ca5e-4fc0-411c-a54c-e321e03de6c2)

## **การเพิ่ม Library EasyKids3in1 ใน Arduino IDE**

เลือกไปที่ Sketch >>> Include Library >>> แล้วเลือก EasyKids3in1

![268210731-9e650eb1-cba6-461f-a7ce-8e6ce894b77d](https://github.com/user-attachments/assets/017db9fd-322f-4fc1-a1c5-21109446797f)

ทำการทดสอบด้วยการกด Verify หากไม่มี Error หรือ ตัวอักษรสีแดงใดๆ แสดงว่าการติดตั้งบอร์ด EasyKids3in1 และไบลารี่เสร็จสมบูรณ์ 100 % 

![268245774-4472cc9e-85e5-43be-a17e-75ba8e2c6b62](https://github.com/user-attachments/assets/eaf92abb-172c-4244-92e3-7faa46e6f0bc)


## **ทดสอบโค้ดตัวอย่าง**

ให้เลือกไปที่ File >>> Examples >>> EasyKids3in1 

โดยโค้ดตัวอย่างจะมีการใช้งานต่างๆ ของหุ่นยนต์ เช่น Input Output Motor LCD RGB เป็นต้น  

![268211308-b0d5a1a2-693d-48fb-af5b-60ba2378d3e7](https://github.com/user-attachments/assets/d0422099-99b3-487a-bcea-c0abebf50a27)


