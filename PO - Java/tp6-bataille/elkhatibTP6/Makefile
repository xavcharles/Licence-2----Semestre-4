all: jar tst clean
	
tst: ShipTest.class SeaTest.class CellTest.class PositionTest.class
	java -jar test-1.7.jar battleship.ShipTest
	java -jar test-1.7.jar battleship.SeaTest
	java -jar test-1.7.jar battleship.CellTest
	java -jar test-1.7.jar battleship.PositionTest


clean:
	rm -rf classes
	rm -f test/battleship/*.class

run: jar
	java -jar battleship.jar

doc:
	cd src; \
	javadoc battleship battleship.direction -d ../docs -author

jar: doc compile
	cd classes; \
	jar cvfm ../battleship.jar ../manifest-ex battleship
	jar cvfm battleship.jar manifest-ex docs test -C classes battleship

compile:
	mkdir classes; \
	cd src; \
	javac battleship/GameMain.java -d ../classes

CellTest.class:
	javac -classpath test-1.7.jar test/battleship/CellTest.java

SeaTest.class:
	javac -classpath test-1.7.jar test/battleship/SeaTest.java

ShipTest.class:
	javac -classpath test-1.7.jar test/battleship/ShipTest.java

PositionTest.class:
	javac -classpath test-1.7.jar test/battleship/PositionTest.java
