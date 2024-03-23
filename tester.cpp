#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "PGMimageProcessor.h"
using namespace ANXTEM001;
template class PGMimageProcessor<Colour>;
template class PGMimageProcessor<Gray>;
TEST_CASE("Image Processor Test"){
    SECTION("Extract Components"){
        PGMimageProcessor<Gray> processor("Birds.pgm");
        PGMimageProcessor<Colour> processor2("Birds.ppm");
        REQUIRE(processor.extractComponents(128,5) == 8);
        REQUIRE(processor2.extractComponents(128,5) == 8);
    }
    SECTION("Filter Components By Size"){
        PGMimageProcessor<Gray> processor("Birds.pgm");
        PGMimageProcessor<Colour> processor2("Birds.ppm");
        processor2.extractComponents(128,1000);
        processor.extractComponents(128,1000);
        REQUIRE(processor.filterComponentsBySize(1000, 5000) == 4);
        REQUIRE(processor2.filterComponentsBySize(1000, 5000) == 4);
    }
    SECTION("Write Components"){
        PGMimageProcessor<Colour> processor("Birds.pgm");
        PGMimageProcessor<Colour> processor2("Birds.ppm");
        processor2.extractComponents(128,5);
        processor.extractComponents(128,5);
        REQUIRE(processor.writeComponents("outfile") == true);
        REQUIRE(processor2.writeComponents("outfile") == true);

    }
    SECTION("Get Largest Component"){
        PGMimageProcessor<Colour> processor("Birds.pgm");
        PGMimageProcessor<Colour> processor2("Birds.ppm");
        processor2.extractComponents(128,5);
        processor.extractComponents(128,5);
        REQUIRE(processor.getLargestSize() == 776);
        REQUIRE(processor2.getLargestSize() == 7016);
    }
    SECTION("Get Smallest Component"){
        PGMimageProcessor<Colour> processor("Birds.pgm");
        PGMimageProcessor<Colour> processor2("Birds.ppm");
        processor2.extractComponents(128,5);
        processor.extractComponents(128,5);
        REQUIRE(processor.getSmallestSize() == 5);
        REQUIRE(processor2.getSmallestSize() == 3584);
    }
    SECTION("Get Component Count"){
        PGMimageProcessor<Colour> processor("Birds.pgm");
        PGMimageProcessor<Colour> processor2("Birds.ppm");
        processor2.extractComponents(128,5);
        processor.extractComponents(128,5);
        REQUIRE(processor.getComponentCount() == 30);
        REQUIRE(processor2.getComponentCount() == 8);
    }
}