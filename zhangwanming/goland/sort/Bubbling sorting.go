package sort

import "fmt"

func BubblingSortBig(arr *[5]int) {
	fmt.Println("排序前", (*arr))
	temp := 0
	for i := 0; i < 4; i++ {
		for j := 0; j < 4-i; j++ {
			if (*arr)[j] > (*arr)[j+1] {
				temp = (*arr)[j]
				(*arr)[j] = (*arr)[j+1]
				(*arr)[j+1] = temp
			}
		}
	}
	fmt.Println("排序后", (*arr))
}
func BubblingSortSmall(arr *[5]int) {
	fmt.Println("排序前", (*arr))
	temp := 0
	for i := 0; i < 4; i++ {
		for j := 0; j < 4-i; j++ {
			if (*arr)[j] < (*arr)[j+1] {
				temp = (*arr)[j]
				(*arr)[j] = (*arr)[j+1]
				(*arr)[j+1] = temp
			}
		}
	}
	fmt.Println("排序后", (*arr))
}
func main() {
	arr := [5]int{54, 15, 65, 25, 45}
	BubblingSortBig(&arr)
}
