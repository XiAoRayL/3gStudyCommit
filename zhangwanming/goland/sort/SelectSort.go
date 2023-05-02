package sort

import "fmt"

// 编写Select Sort完成排序
func SelectSort(arr []int) {
	//标准访问方式
	//(*arr)[1] = 600
	//arr[1] = 900
	//假设arr[0]最大值
	//遍历后面进行比较
	for j := 0; j < len(arr)-1; j++ {
		max := arr[j]
		maxIndex := j
		for i := j + 1; i < len(arr); i++ {
			if max > arr[i] { //找到真正的最大值
				max = arr[i]
				maxIndex = i
			}
		}
		//交换
		if maxIndex != j {
			arr[j], arr[maxIndex] = arr[maxIndex], arr[j]
		}
	}
	fmt.Println("第一次", arr)
}
