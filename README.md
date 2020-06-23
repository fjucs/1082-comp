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

---

* Week10
  * A Uva 10718 Bit Mask
    * 如果在沒有上下界時，答案就是 M = `~N`，可是多了上下界 [L, U] 就會影響到 M
    * 當 N=0 時 M 希望變成 1 (因為 N or M 要 maxmium)
      * 因為是 0->1 所以可能會超過 U
      * 當 N=0 時 M = 1 且 M <= U
    * 當 N=1 時，M 希望變成 0 (因為題目要求 M 最小值)
      * 因為是 1->0 所以可能會小於 L
      * 當 N=1 時 M = 0 且 M >= L
        * 如果 M=1 時，則代表 M=1 的情況下仍 < L

  * B Uva 1073

* Week11
  * A Uva 1623 Enter The Dragon
    * 貪心
      * 每次遇到一個滿水的湖，就往前找上一次滿水之後第一天沒有下雨且沒有喝水的那天，來給龍喝水
  * B Uva 11997

* Week12
  * A Uva 10440
    * 有 m 台車 一次可以載 n 台車 載一趟要花 t 分鐘(來回分開算)，今天給你車子到港口的時間，要你算載完全部要花多少時間
      * 情況 m < n
        * 可以一次載完，時間 = 最後一輛車加上回來的時間(t)
      * 情況 m > n
        * m % n == 0
          * 一次載 n 輛車過去，每次看回來的時候，下一組有沒有全部到港口(直接看該組的最後一台車跟回來的時間取 max)
        * m % n != 0
          * 先載 m % n (餘數)
          * 剩下的則跟整除一樣

  * B Uva 11383

* Week13
  * A Uva 10700
    * 「先加減後乘除」(max)跟「先乘除後加減」(min)
  * B Uva 11865

* Week14
  * A Uva 10366
    * 倒水 超麻煩
  * B Uva 10236

* Week15
  * A Uva 11722
    * 碰面的條件：t1 <= x <= t2 且 s1 <= y <= s2
      * 因為要碰面勢必兩者的差距要在 w 之內，也就是 |x-y| <= w
      * 得到 x-y >= -w, x-y <= w
        * i.e. x-y+w >= 0 以及 x-y-w <= 0 = 兩條線穿過長方形的面積
        * 問題轉換成碰面的機率 = 兩條直線圍起的面積 / 總面積
    * 簡化問題
      * 兩條線圍起的面積 = x-y+w=0上面的面積 - x-y-w=0 上面的面積 (排容)
      * ![](https://i.imgur.com/mGwHzYq.png)
    * 探討一條線可能交到長方形的哪一邊
      * 完全沒有（在長方形的上方）
      * 左邊 + 右邊 (長方形夠高的話)
        ![](https://i.imgur.com/BSymM49.png)
      * 左邊 + 上邊
        ![](https://i.imgur.com/O4H4cQ5.png)
      * 上邊 + 下邊 （長方形夠寬的話）
        ![](https://i.imgur.com/5fEcZdD.png)
      * 右邊 + 下邊
        ![](https://i.imgur.com/XbrXcaI.png)
    * 判斷線有無碰到邊？
      * 上 t1 <= top x <= t2
      * 左 s1 <= left y <= s2
      * 下 t1 <= bx <= t2
      * 右 s1 <= ry <= s2
      ![](https://i.imgur.com/h0UT97c.png)
      ![](https://i.imgur.com/9QI8iG3.png)

> 有看到純幾何的做法：https://morris821028.github.io/2014/07/06/oj/uva/uva-11722/

  * B Uva 11542

* Week16
  * A Uva 10982 x
  * B Uva 1494
