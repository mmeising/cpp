# ex00 btc
map with date and value?
list (doubly linked list) to get the previous value when no value for that date is present?

Used std::list<std::pair<std::string, float> >


# ex01 RPN
stack for LIFO handling?

Used std::stack<float>


# ex02 PmergeMe
(handle at least 3000 different integers, use merge-insert sort algorithm to sort positive integer sequence)
two different containers:
deque (using it like a list/array basically)
vector (close to array usage)

split input into multiple vectors max size 10
└─> constructor     with begin and end iterators
└─> erase from main with begin and end iterators

clear main vector
insertion sort all small vectors
merge sort these vectors into the main one


1 9 2 5 4 3 6 8 7 0 11 10 14 13 15 19 16 18 17 12 22 21 23 20