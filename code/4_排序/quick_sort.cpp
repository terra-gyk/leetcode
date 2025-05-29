#include <iostream>
#include <vector>
#include <stack>

// 快速排序的划分函数
int partition(std::vector<int>& arr, int left, int right) 
{
  int pivot = arr[right];  // 选择最右边的元素作为基准
  int i = left - 1;    // i 指向比 pivot 小的区域的最后一个元素

  for (int j = left; j < right; ++j) 
  {
    if (arr[j] <= pivot) 
    {
      ++i;
      std::swap(arr[i], arr[j]);  // 把小于等于 pivot 的元素放到左边
    }
  }

  std::swap(arr[i + 1], arr[right]);  // 把 pivot 放到中间位置
  return i + 1;  // 返回 pivot 的最终位置
}

// 快速排序主函数（递归）
void quick_sort(std::vector<int>& arr, int left, int right) 
{
  if (left < right) 
  {
    int pi = partition(arr, left, right);  // 划分数组

    // 对左右两部分分别递归排序
    quick_sort(arr, left, pi - 1);
    quick_sort(arr, pi + 1, right);
  }
}



// 随机选择 pivot 并进行划分
int randomized_partition(std::vector<int>& arr, int left, int right) 
{
  std::srand(static_cast<unsigned int>(time(0)));
  int randomIndex = left + rand() % (right - left + 1);  // 随机选择 pivot 索引
  std::swap(arr[randomIndex], arr[right]);         // 把 pivot 移到最右边
  return partition(arr, left, right);          // 复用之前的 partition
}

// 快速排序主函数（递归）
void randomized_quick_sort(std::vector<int>& arr, int left, int right) 
{
  if (left < right) 
  {
    int pi = randomized_partition(arr, left, right);

    randomized_quick_sort(arr, left, pi - 1);
    randomized_quick_sort(arr, pi + 1, right);
  }
}



// 三路快速排序（3-Way Quick Sort）
void three_way_quick_sort(std::vector<int>& arr, int left, int right) 
{
  if (left >= right) return;

  int lt = left, gt = right;
  int pivot = arr[left];
  int i = left;

  while (i <= gt) 
  {
    if (arr[i] < pivot)
      std::swap(arr[i++], arr[lt++]);
    else if (arr[i] > pivot)
      std::swap(arr[i], arr[gt--]);
    else
      ++i;
  }

  // 递归排序小于和大于 pivot 的部分
  three_way_quick_sort(arr, left, lt - 1);
  three_way_quick_sort(arr, gt + 1, right);
}



// 非递归快排（Iterative Quick Sort）
void iterative_quick_sort(std::vector<int>& arr) 
{
  std::stack<std::pair<int, int>> stack;
  stack.push({0, static_cast<int>(arr.size()) - 1});

  while (!stack.empty()) 
  {
    auto [left, right] = stack.top();
    stack.pop();

    if (left >= right) continue;

    int pi = partition(arr, left, right);

    stack.push({pi + 1, right});
    stack.push({left, pi - 1});
  }
}



// 优化小数组插入排序结合快排
const int INSERTION_SORT_THRESHOLD = 10;

void optimized_quick_sort(std::vector<int>& arr, int left, int right) 
{
  if (left >= right) return;

  // 对小数组使用插入排序
  if (right - left <= INSERTION_SORT_THRESHOLD) 
  {
    for (int i = left + 1; i <= right; ++i) 
    {
      int key = arr[i];
      int j = i - 1;
      while (j >= left && arr[j] > key) 
      {
        arr[j + 1] = arr[j];
        --j;
      }
      arr[j + 1] = key;
    }
    return;
  }

  int pi = partition(arr, left, right);
  optimized_quick_sort(arr, left, pi - 1);
  optimized_quick_sort(arr, pi + 1, right);
}

// 打印数组函数
void print_array(const std::vector<int>& arr) 
{
  for (int num : arr) 
  {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}



// 主函数测试
int main() 
{
  std::vector<int> arr = {10, 7, 8, 9, 1, 5};

  std::cout << "原始数组: ";
  print_array(arr);

  quick_sort(arr, 0, arr.size() - 1);

  std::cout << "排序后数组: ";
  print_array(arr);

  return 0;
}

