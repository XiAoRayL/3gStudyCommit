package main

import "fmt"

type FamilyAccount struct {
	//申明字段
	//用key来表示进入的功能
	key string
	//用loop来判断是否退出
	loop bool
	//定义账户余额
	balance float64
	//定义收支的资金数
	money float64
	//定义变量，记录是否有收支的行为
	flag bool
	//定义资金的说明
	note    string
	details string
}

// 对结构体进行赋初始值
func NewFamilyAccount() *FamilyAccount {
	return &FamilyAccount{
		key:     "",
		loop:    true,
		balance: 1000.0,
		money:   0.0,
		note:    "",
		flag:    false,
		details: "收支\t账户金额\t收支金额\t说  明",
	}
}

// 将显示明细写成方法
func (this *FamilyAccount) ShowDetails() {
	//进行判断
	if this.flag == true {
		fmt.Println("------------------收支明细------------------")
		fmt.Println(this.details)
	} else {
		fmt.Println("没有收支的行为")
	}
}

// 将登记收入写成方法
func (this *FamilyAccount) Income() {
	fmt.Println("------------------登记收入------------------")
	fmt.Println("本次收入金额：")
	fmt.Scanln(&this.money)
	//资金进行改变
	this.balance += this.money
	fmt.Println("本次收入说明：")
	fmt.Scanln(&this.note)
	//进行拼接
	this.details += fmt.Sprintf("\n收入\t%v\t%v\t%v", this.balance, this.money, this.note)
	//进行转换
	this.flag = true
}

// 将支出写成方法
func (this *FamilyAccount) Pay() {
	fmt.Println("------------------登记支出------------------")
	fmt.Println("本次支出金额：")

	fmt.Scanln(&this.money)
	if this.money > this.balance {
		fmt.Println("资金余额不足")
	}
	//资金进行改变
	this.balance -= this.money
	fmt.Println("本次收入说明：")
	fmt.Scanln(&this.note)
	//进行拼接
	this.details += fmt.Sprintf("\n支出\t%v\t%v\t%v", this.balance, this.money, this.note)
	//进行转换
	this.flag = true
}

// 将退出写成方法
func (this *FamilyAccount) Exit() {
	//进行是否退出的判断
	fmt.Println("您确定要退出嘛？y/n")
	choice := ""
	for {
		//输入判断的方法
		fmt.Scanln(&choice)
		if choice == "y" || choice == "n" {
			break
		}
		fmt.Println("您的输入有误，请重新输入")
	}
	if choice == "y" {
		this.loop = false
	}
	fmt.Println("------------------退出软件------------------")
}

// 给结构体绑定相应方法
// 显示主菜单
func (this *FamilyAccount) MainMenu() {
	for {
		fmt.Println("------------------家庭收支记账软件------------------")
		fmt.Println("                   1.收支明细")
		fmt.Println("                   2.登记收入")
		fmt.Println("                   3.登记支出")
		fmt.Println("                   4.退出软件")
		fmt.Println("请选择1——4：")
		fmt.Scanln(&this.key)
		//利用switch进行选择
		switch this.key {
		case "1":
			this.ShowDetails()
		case "2":
			this.Income()
		case "3":
			this.Pay()
		case "4":
			this.Exit()
		default:
			fmt.Println("请输入正确的选项...")
		}
		if !this.loop {
			break
		}
	}
}
func main() {
	//进行面向对象的方式完成
	//NewFamilyAccount().MainMenu()
	a := NewFamilyAccount()
	a.MainMenu()
}

//func main() {
//	//用key来表示进入的功能
//	key := ""
//	//用loop来判断是否退出
//	loop := true
//	//定义账户余额
//	balance := 10000.0
//	//定义收支的资金数
//	money := 0.0
//	//定义变量，记录是否有收支的行为
//	flag := false
//	//定义资金的说明
//	note := ""
//	details := "收支\t账户金额\t收支金额\t说  明"
//	//显示主菜单
//	for {
//		fmt.Println("------------------家庭收支记账软件------------------")
//		fmt.Println("                   1.收支明细")
//		fmt.Println("                   2.登记收入")
//		fmt.Println("                   3.登记支出")
//		fmt.Println("                   4.退出软件")
//		fmt.Println("请选择1——4：")
//		fmt.Scanln(&key)
//		switch key {
//		case "1":
//			//进行判断
//			if flag == true {
//				fmt.Println("------------------收支明细------------------")
//				fmt.Println(details)
//			} else {
//				fmt.Println("没有收支的行为")
//			}
//
//		case "2":
//			fmt.Println("------------------登记收入------------------")
//			fmt.Println("本次收入金额：")
//			fmt.Scanln(&money)
//			//资金进行改变
//			balance += money
//			fmt.Println("本次收入说明：")
//			fmt.Scanln(&note)
//			//进行拼接
//			details += fmt.Sprintf("\n收入\t%v\t%v\t%v", balance, money, note)
//			//进行转换
//			flag = true
//		case "3":
//			fmt.Println("------------------登记支出------------------")
//			fmt.Println("本次支出金额：")
//
//			fmt.Scanln(&money)
//			if money > balance {
//				fmt.Println("资金余额不足")
//				continue
//			}
//			//资金进行改变
//			balance -= money
//			fmt.Println("本次收入说明：")
//			fmt.Scanln(&note)
//			//进行拼接
//			details += fmt.Sprintf("\n支出\t%v\t%v\t%v", balance, money, note)
//			//进行转换
//			flag = true
//		case "4":
//			//进行是否退出的判断
//			fmt.Println("您确定要退出嘛？y/n")
//			choice := ""
//			for {
//				fmt.Scanln(&choice)
//				if choice == "y" || choice == "n" {
//					break
//				}
//				fmt.Println("您的输入有误，请重新输入")
//			}
//			if choice == "y" {
//				loop = false
//			}
//			fmt.Println("------------------退出软件------------------")
//		default:
//			fmt.Println("请输入正确的选项...")
//		}
//		if !loop {
//			break
//		}
//	}
//	fmt.Println("您已经退出了程序")
//
//}
