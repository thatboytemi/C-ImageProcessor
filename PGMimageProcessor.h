#include <string>
#include "ConnectedComponent.h"
#include <memory>
namespace ANXTEM001{
    //will be used for templated code
    typedef unsigned char Gray;
    struct Colour{
        unsigned char pixels[3];
    };

    template <typename T> class PGMimageProcessor{
        private:
            int imageWidth =0;
            int imageHeight =0;
            //identifier not used for PGMimageProcessor object but for components within a PGMimageProcessor class
            int identifier =0;
            std::string filename;
            std::vector<std::unique_ptr<ConnectedComponent>> components;
        public:
            //Constructors
            PGMimageProcessor();
            PGMimageProcessor(const PGMimageProcessor & other);
            PGMimageProcessor(PGMimageProcessor && other);
            PGMimageProcessor & operator=(const PGMimageProcessor & rhs);
            PGMimageProcessor & operator=(PGMimageProcessor && rhs);
            PGMimageProcessor(std::string filename);
            ~PGMimageProcessor();
            /* process the input image to extract all the connected components,
            based on the supplied threshold (0...255) and excluding any components
            of less than the minValidSize. The final number of components that
            you store in your container (after discarding undersized one)
            must be returned.
            */

            int extractComponents(unsigned char threshold, int minValidSize);

            /* iterate - with an iterator - though your container of connected
            components and filter out (remove) all the components which do not
            obey the size criteria pass as arguments. The number remaining
            after this operation should be returned.
            */

            int filterComponentsBySize(int minSize, int maxSize);

            /* create a new PGM file which contains all current components
            (255=component pixel, 0 otherwise) and write this to outFileName as a
            valid PGM. the return value indicates success of operation
            */

            bool writeComponents(const std::string & outFileName);

            // return number of components

            int getComponentCount(void) const;
            
            // return number of pixels in largest component

            int getLargestSize(void) const;

            // return number of pixels in smallest component

            int getSmallestSize(void) const;

            /* print the data for a component to std::cout
            see ConnectedComponent class;
            print out to std::cout: component ID, number of pixels
            */

            void printComponentData(const ConnectedComponent & theComponent) const;

            bool writeBorder(const std::string & outFileName);
            //prints output string when user chooses -p command
            void getString();
            //read original image in
            T* readFile(std::string filename, int offset);
    };

}
