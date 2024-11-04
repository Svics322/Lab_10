#include "pch.h"
#include "CppUnitTest.h"
#include"..\PDS_10\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
    {
	public:

        TEST_METHOD(TestAddEdge)
        {
            Graph graph(6);
            graph.addEdge(1, 2, 1);
            graph.addEdge(1, 3, 6);
            graph.addEdge(1, 4, 2);
          
            Assert::AreEqual(3u, static_cast<unsigned int>(graph.adjList[0].size()));
            Assert::AreEqual(2u, graph.adjList[0][0].to + 1);
        }

        TEST_METHOD(TestWeightMatrixOutput)
        {
            Graph graph(6);
            graph.addEdge(1, 2, 1);
            graph.addEdge(1, 3, 6);
            graph.addEdge(1, 4, 2);
          
            graph.printWeightMatrix();
         
            Assert::AreEqual(0u, graph.weightMatrix[0][0]); 
            Assert::AreEqual(1u, graph.weightMatrix[0][1]); 
            Assert::AreEqual(6u, graph.weightMatrix[0][2]); 
            Assert::AreEqual(2u, graph.weightMatrix[0][3]); 
            Assert::AreEqual(Graph::INF, graph.weightMatrix[0][4]);
            Assert::AreEqual(Graph::INF, graph.weightMatrix[0][5]);
        }

        TEST_METHOD(TestSaveWeightMatrixToFile)
        {
            Graph graph(6);
            graph.addEdge(1, 2, 1);
            graph.addEdge(1, 3, 6);
            graph.addEdge(1, 4, 2);
          
            graph.saveWeightMatrixToFile("output_matrix.txt");
           
        }
	};
}
