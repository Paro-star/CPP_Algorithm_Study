cmake_minimum_required(VERSION 3.28)
project(CPP_Algorithm_Study)

set(CMAKE_CXX_STANDARD 17)

# --- NHÓM CLASSWORK ---
add_executable(DictionarySort ClassWork/ClassWork_02/DictionarySort/DictionarySort.cpp)
add_executable(IndexSummation ClassWork/ClassWork_02/IndexSummation/IndexSummation.cpp)
add_executable(StudentSort_SwapCount ClassWork/ClassWork_02/StudentSort_SwapCount/StudentSort_SwapCount.cpp)
add_executable(TriangleSort ClassWork/ClassWork_02/TriangleSort/TriangleSort.cpp)
add_executable(TextingApp ClassWork/ClassWork_03/TextingApp/TextingApp.cpp)
add_executable(LinkListCheckCycle ClassWork/ClassWork_03/LinkedListCheckCycle/LinkedListCheckCycle.cpp)
add_executable(ReducedPath ClassWork/ClassWork_03/ReducedPath/ReducedPath.cpp)
add_executable(SpliceRotation ClassWork/ClassWork_03/SpliceRotation/SpliceRotation.cpp)

# --- NHÓM DATA STRUCTURES ---
add_executable(BasicQueue DataStructures/BasicQueue/BasicQueue.cpp)
add_executable(BasicStack DataStructures/BasicStack/BasicStack.cpp)

# --- NHÓM HOMEWORK 01 ---
add_executable(Chain HomeWork/Homework_01/Chain/Chain.cpp)
add_executable(Envelope HomeWork/Homework_01/Envelope/Envelope.cpp)
add_executable(FindMex HomeWork/Homework_01/FindMex/FindMex.cpp)
add_executable(InsertionSort HomeWork/Homework_01/InsertionSort/InsertionSort.cpp)
add_executable(LinearSearch HomeWork/Homework_01/LinearSearch/LinearSearch.cpp)
add_executable(LinearSearchSorted HomeWork/Homework_01/LinearSearchSorted/LinearSearchSorted.cpp)
add_executable(Lychrel HomeWork/Homework_01/Lychrel/Lychrel.cpp)
add_executable(MinComparisonSort HomeWork/Homework_01/MinComparisonSort/MinComparisonSort.cpp)
add_executable(Renew HomeWork/Homework_01/Renew/Renew.cpp)
add_executable(SelectionSort HomeWork/Homework_01/SelectionSort/select_sort.cpp)
add_executable(Wall HomeWork/Homework_01/Wall/Wall.cpp)

# --- NHÓM HOMEWORK 02 & 03 ---
add_executable(HeapDraw HomeWork/Homework_02/HeapDraw/HeapDraw.cpp)
add_executable(HeapifyDown HomeWork/Homework_02/HeapifyDown/HeapifyDown.cpp)
add_executable(MergeSortVisualization HomeWork/Homework_02/MergeSortVisualization/MinhHoaMergeSort.cpp)
add_executable(BracketChecker HomeWork/Homework_03/BracketChecker/BracketChecker.cpp)
add_executable(Ferry HomeWork/Homework_03/Ferry/Ferry.cpp)
add_executable(OnlineSorting HomeWork/Homework_03/OnlineSorting/OnlineSorting.cpp)
add_executable(WorstCase HomeWork/Homework_03/WorstCase/WorstCase.cpp)
add_executable(OnlineOflineWithRank HomeWork/Homework_03/OnlineOflineWithRank/OnlineOflineWithRank.cpp)
# --- NHÓM SEARCH & SORT ---
add_executable(SearchBasic Search/BasicSearch/Search.cpp)
add_executable(SearchVD1 Search/BasicSearch/VD_1.cpp)
add_executable(CommonSort Sort/CommonSort/sort.cpp)
add_executable(CountingSort Sort/CountingSort/CountingSort.cpp)
add_executable(MergeSort Sort/MergeSort/MergeSort.cpp)
add_executable(RadixSort Sort/RadixSort/RadixSort.cpp)
add_executable(QuickSort Sort/QuickSort/QuickSort.cpp)