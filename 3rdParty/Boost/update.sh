if [ -z "$1" ]; then
	echo "Please specify the location of the boost source tree"
	exit -1
fi

TARGET_DIR=src

./bcp --boost="$1" \
	tools/bcp \
	bind.hpp \
	date_time/posix_time/posix_time.hpp \
	foreach.hpp \
	filesystem.hpp \
	filesystem/fstream.hpp \
	noncopyable.hpp \
	numeric/conversion/cast.hpp \
	shared_ptr.hpp \
  optional.hpp \
	signals.hpp \
	thread.hpp \
	asio.hpp \
	regex.hpp \
	$TARGET_DIR

rm -rf $TARGET_DIR/libs/config
rm -rf $TARGET_DIR/libs/smart_ptr

LIBS="date_time regex system thread signals filesystem"
for lib in $LIBS; do
	rm -rf $TARGET_DIR/libs/$lib/build $TARGET_DIR/libs/$lib/*.doc $TARGET_DIR/libs/$lib/src/*.doc $TARGET_DIR/libs/$lib/src/CMakeLists.txt $TARGET_DIR/libs/$lib/test
done
rm -rf $TARGET_DIR/tools/bcp/*.html $TARGET_DIR/libs/test $TARGET_DIR/doc $TARGET_DIR/boost.png $TARGET_DIR/boost/test
