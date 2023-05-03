package sort

func QuickSort01(Array []int, left, right int) {
	l := left
	r := right
	//pivot 是中轴，支点
	pivot := Array[(left+right)/2]
	//for循环的目的是将比pivot小的数和大的数左右交换
	for l < r {
		//从pivot的左边找到大于等于pivot的值
		for Array[l] < pivot {
			l++
		}
		//从pivot的右边找到小于等于pivo的值
		for Array[r] > pivot {
			r--
		}
		//l >= r 表明本次分解任务完成，break
		if l >= r {
			break
		}
		//交换
		Array[l], Array[r] = Array[r], Array[l]
		//优化
		if Array[l] == pivot {
			r--
		}
		if Array[r] == pivot {
			l++
		}
	}
	//如果 l == r ,再移动下
	if l == r {
		l++
		r--
	}
	//向左
	if left < r {
		QuickSort01(Array, left, r)
	}
	//向右
	if right > l {
		QuickSort01(Array, l, right)
	}
}
