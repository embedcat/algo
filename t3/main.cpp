#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

typedef std::pair <int, int> Segment;

bool my_pair_sort(Segment s1, Segment s2)  {
	return (s1.second < s2.second);
}

std::vector <int> get_covering_set(std::vector <Segment> segments) {
  std::vector <int> result;
	std::sort(segments.begin(), segments.end(), my_pair_sort);

  for (std::size_t i = 0; i < segments.size(); i++) {
    int cur_dot = segments[i].second;
		result.push_back(cur_dot);
		
    while (i < segments.size() && segments[i+1].first <= cur_dot) {
    	i++;
		}
  }

  return result;
}

int main(void) {
  int segments_count;
  std::cin >> segments_count;
  std::vector <Segment> segments(segments_count);
  for (int i = 0; i < segments_count; i++) {
    std::cin >> segments[i].first >> segments[i].second;
  }

  std::vector <int> points = get_covering_set(segments);
  std::cout << points.size() << std::endl;
  for (std::size_t i = 0; i < points.size(); i++) {
    std::cout << points[i] << " ";
  }
  std::cout << std::endl;
}
