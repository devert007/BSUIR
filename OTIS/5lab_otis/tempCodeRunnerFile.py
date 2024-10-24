def make_binary_tree(graph):###########################3
  # graph = graph.to_directed()
  if not nx.is_tree(graph):
        raise ValueError("The input graph is not a tree.")
    # Create a binary tree
  binary_tree = nx.DiGraph()
  for node in graph.nodes():
    children = list(graph.neighbors(node))
    if len(children) > 2:
      raise ValueError("The input graph has more than two children for a node.")
    elif len(children) == 2:
      binary_tree.remove_edge(node, children[1])
      binary_tree.add_edge(node, children[0])
      binary_tree.add_edge(children[0], children[1])
  return binary_tree