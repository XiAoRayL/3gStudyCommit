package sort

func QuickSort(SortArray []int, left, right, Max int) {
	if left < right {
		key := SortArray[left]
		i := left
		j := right
		for {
			for i+1 < Max {
				i++
				if key <= SortArray[i] {
					break
				}
			}
			for j-1 >= 0 {
				if key >= SortArray[j] {
					break
				}
				j--
			}
			if i >= j {
				break
			}
			SortArray[i], SortArray[j] = SortArray[j], SortArray[i]
		}
		SortArray[left] = SortArray[j]
		SortArray[j] = key
		QuickSort(SortArray, left, j-1, Max)
		QuickSort(SortArray, j+1, right, Max)
	}
}
