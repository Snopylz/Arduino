# Arduino学习

数字信号 	Digital Signal

模拟信号	 	Analog Signal

Serial.begin (9600) 	设置串口波特率

status = digitalRead(pin)		读取数字pin引脚的状态

Serial.println(status)	打印出引脚的状态

>说下模拟信号与数字信号的区别：
>
>数字(Digital Signal): 只有2个值(0V和5V)。运用在Arduino中，就是高(HIGH)或者低(LOW)，“HIGH”是“1”，对应为5V。“LOW”是“0”，对应为0V。
>
>模拟(Analog Signal): 在一定范围内，有无限值。在Arduino中模拟口中，已经将0V到5V之间的值映射为0~1023范围内的值。比如，0对应为0V，1023对应为5V，512对应为2.5V。

关于Arduino的文件命名一定不能与库名相同，会报错。

>lcd.init() 			 	//LCD初始化
>
>lcd.backlight()		//打开LCD背光灯
>
>lcd.print (DHT.temperature, 1 )    //目前预估计1第二个参数为保留小数点后几位数字。
>
>lcd.setCursor(8, 1)	//设置LCD光标停留的位置，8为第8个字符的位置，print在其下一位输			     
>
>​					// 出。1为第二行，初始第一行标记为0。

