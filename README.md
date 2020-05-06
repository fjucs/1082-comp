# 109 competitive programming

* Week2
  * A Uva 11157 貪心
    * 把問題轉化成:有兩個青蛙同時從左往右，大的石頭能站兩隻、小的能站一隻
    * 在更新過程中取找最大的距離
    * 起點跟終點可以當成大石頭 (B-0 B-d)
  * B Uva 12124 二分答案
    * 直接做 => 炸裂
      * 先從所有零件種類的最小品質開始挑，如果當前的 budget 沒有爆的話，從品質最小的零件種類開始改進
    * 二分答案 (此題是最小值最大化)
      * 假設答案是 x ，刪除所有品質小於 x 的配件，如果可以組裝出不超過 b 元的電腦，那答案一定大於等於 x；如果不能組裝出不超過 b 元的電腦，答案小於 x

> 參考
> <https://blog.csdn.net/SunnyYoona/article/details/23966381>

* Week 3
  * A Uvalive 2519
    * 把問題轉成由小島為中心，畫出長度 d 的圓，與 x 軸相交的長度，也就是 [x-dis, x+dis] where dis = sqrt(d^2 - y^2)
    * 線段代表雷達站可以設在該線段內，而兩線段相交代表的範圍代表雷達設在那裏可以蓋到兩個小島
    * 把所有線段照右端點 sort ，選定第一個當起點，接著往下看下個線段的左端點是否在起點的範圍內，如果是代表不用多設置雷達站；如果不在範圍內，則代表要多設置一個雷達站才能覆蓋到新的小島，要把起點更新到新的線段之右端點。
    * 為什麼要看「下個線段的左端點是否小於等於上個線段的右端點」?
      * 要判斷兩個線斷是否交疊 => 不用設雷達站
  * B Uva 1335 二分答案+貪心
    * 想法
      * n=偶數
        * 答案=![](https://render.githubusercontent.com/render/math?math=max%5C%7Br%5Bi%5D%2Br%5Bi%2B1%5D%5C%7D%2C%20r%5Bn%2B1%5D%3Dr%5B1%5D)
      * n=奇數
        * 把物品分成兩堆，編號偶數的從左堆開始拿（不夠往右拿）；編號奇數的從右堆開始拿（不夠往左拿）
        * 拿第 i 個時，要看第 i-1 個已經從那堆中拿的份要扣除
          * e.g.
            * 物品左2右3
            * i=2 要2個；i=3 要2個
            * i=2 左0右2
            * 所以 i=3 從右邊拿 ![](https://render.githubusercontent.com/render/math?math=3_%7B(%5Ctext%7Bright%20total%7D)%7D-2_%7B(i%3D2%20%5Ctext%7Bright%7D)%7D%3D1_%7B(i%3D3%20%5Ctext%7Bright%7D)%7D) 個，從左邊拿 ![](https://render.githubusercontent.com/render/math?math=2_%7B(i%3D3%5Ctext%7Btarget)%7D%7D-1_%7B(i%3D3%20%5Ctext%7B%20right%7D)%7D%3D1_%7B(i%3D3%20%5Ctext%7B%20left%7D)%7D) 個
        * 判斷最後一個(奇數)有沒有拿左邊，有=不滿足條件，沒有=滿足條件
        * 用二分答案找最小的 p 滿足條件
    * Use 1-index

> https://www.cnblogs.com/riasky/p/3464915.html
> https://blog.csdn.net/qq_41289920/article/details/84838131
> https://blog.csdn.net/shuangde800/article/details/8708371
> https://www.cnblogs.com/kickit/p/7619889.html

* Week4
  * A Uva 11549
  * B Uva 11264

* Week5
  * A Uva 410
  * B Uva 10859

* Week6
  * A Uva 311
  * B Uva 11367

* Week7
  * A Uva 10714
  * B Uva 1362

* Week9
  * A Uva 10718 Bit Mask
  * B Uva 1073
