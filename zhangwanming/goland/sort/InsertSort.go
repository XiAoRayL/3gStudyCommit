package sort

import "fmt"

func InsertSort(arr []int) {
	//完成第一次，给第二个元素找到最合适的地方
	for i := 1; i < len(arr); i++ {
		insertVal := arr[i]
		insertIndes := i - 1
		//从小到大
		for insertIndes >= 0 && arr[insertIndes] < insertVal {
			arr[insertIndes+1] = arr[insertIndes] //数据后移
			insertIndes--
		}
		//插入
		if insertIndes+1 != i {
			arr[insertIndes+1] = insertVal
		}

	}
	fmt.Println(arr)
}
