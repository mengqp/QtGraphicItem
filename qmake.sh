# !/bin/zsh

make distclean
echo "./qmake.sh [type] type = cd/dd/cr(cross debug/desk debug/cross releas), other default is cr"

APPPATH=./Debug/
APPNAME=GraphicsItemDev
PRONAME=$APPNAME.pro
TARGET=$APPPATH$APPNAME

if [ $# -ne 1 ];
then
	echo "param is default"
	exit
# else
	# echo $1
fi

if [ "$1"x = "cd"x ];
then
	echo "cross debug project"
	QMAKE=/opt/qt-everywhere-opensource-src-4.7.3/bin/qmake
	CONFIG="CONFIG+=Debug"
	# SQLITE3="LIBS+=libsqlite3.so.0"
elif [ "$1"x = "dd"x ];
then
	echo "desk debug project"
	# QMAKE=/home/mengqp/mengqp/pro/qt/qtsdk-2010.05/qt/bin/qmake
	QMAKE=/usr/bin/qmake-qt4
	CONFIG="CONFIG+=Debug"
	# SQLITE3="LIBS+=libsqlite3linux.so.0"
elif [ "$1"x = "cr"x ];
then
	echo "cross release project"
	QMAKE=/opt/qt-everywhere-opensource-src-4.7.3/bin/qmake
	CONFIG="CONFIG+=release"
	# SQLITE3="LIBS+=libsqlite3.so.0"
else
	echo "cross release project"
	QMAKE=/opt/qt-everywhere-opensource-src-4.7.3/bin/qmake
	CONFIG="CONFIG+=release"
	# SQLITE3="LIBS+=libsqlite3.so.0"
fi

$QMAKE -project -Wall  -o  $PRONAME -after TARGET=$TARGET $CONFIG $SQLITE3 "OBJECTS_DIR = ./build/obj/" "MOC_DIR = build/moc/" "UI_DIR=build/ui"   "QT += gui core sql xml"
$QMAKE -makefile $PRONAME   -o ./Makefile

make
