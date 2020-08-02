#ifndef CUBBYDNN_GRAPH_BUILDER_HPP
#define CUBBYDNN_GRAPH_BUILDER_HPP

#include <CubbyDNN/Core/Shape.hpp>
#include <CubbyDNN/Initializer/InitializerWrapper.hpp>
#include <CubbyDNN/Node/NodeWrapper.hpp>

#include <random>
#include <string_view>

namespace CubbyDNN::Core
{
class Graph;

class GraphBuilder
{
 public:
    GraphBuilder(Graph* _graph);

    void RegisterStandardNodeType();

    Node::NodeWrapper Input(const std::string& nodeName);
    Node::NodeWrapper Parameter(const std::string& nodeName, const Shape& shape,
                                Initializer::InitializerWrapper initializer);

    Node::NodeWrapper ReLU(Node::NodeWrapper logit, float alpha = 0.0f);
    Node::NodeWrapper Softmax(Node::NodeWrapper logit,
                              const std::vector<bool>& reduceAxis);

    Node::NodeWrapper Dense(Node::NodeWrapper input, Node::NodeWrapper weight,
                            Node::NodeWrapper bias);

    Node::NodeWrapper SoftmaxCE(Node::NodeWrapper label,
                                Node::NodeWrapper prob);

    Initializer::InitializerWrapper InitConstant(float constant = 0.0f);
    Initializer::InitializerWrapper InitXavier(
        std::mt19937_64::result_type seed, std::size_t fanIn,
        std::size_t fanOut);

    Graph* const graph;
};
}  // namespace CubbyDNN::Core

#endif