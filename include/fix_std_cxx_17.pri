## can be used with Qt 5.12 and later.
## For Qt 5.11 and earlier, it is not a recognized QMake flag and you have to get your hands a bit dirty.
##
## Reference: https://stackoverflow.com/questions/46610996/cant-use-c17-features-using-g-7-2-in-qtcreator


lessThan(QT_MAJOR_VERSION, 5)
{
	QMAKE_CXXFLAGS += -std=c++17
}

isEqual(QT_MINOR_VERSION, 5) : lessThan(QT_MINOR_VERSION, 12)
{
	QMAKE_CXXFLAGS += -std=c++17
}
