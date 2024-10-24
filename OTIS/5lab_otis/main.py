import networkx as nx
import matplotlib.pyplot as plt


def showMenu():
  print("Graph Menu:")
  print("1. Create graph")
  print("2. Rename graph ")
  print("3. Print info about graph ")
  print("4. Add node")
  print("5. Remove node")
  print("6. Rename node")
  print("7. Move node ")
  choose_client = input("Enter your choose: ")
  return choose_client


def create_graph():
  G = nx.Graph()
  G.name = input ("Graph name: " )
  while(input("Do you want to add node(y/n)")=='y'):
    node_name = input("Enter node info: ")
    G.add_node(node_name)
  if(G.number_of_nodes()>2):
    if(input("Do you want to add edge to nodes(y/n)")=='y'):
      source_node = input("Enter the source node: ")
      target_node = input("Enter the target node: ")
      if source_node in G.nodes() and target_node in G.nodes():
        G.add_edge(source_node, target_node)
  return G

def add_node(graph):
  node_name = input("Enter node info: ")
  graph.add_node(node_name)
def rename_graph():
  G.name = input("New graph name: ")
  return G
def create_edge():
  source_node = input("Enter the source node: ")
  target_node = input("Enter the target node: ")
  if source_node in G.nodes() and target_node in G.nodes():
    G.add_edge(source_node, target_node)
  else:
    print(f"Node {source_node} or {target_node} not found in the graph.")
  return G
def remove_edge(source_node, target_node):

  if source_node in G.nodes() and target_node in G.nodes():
    graph.remove_edge(source_node, target_node)
  else:
    print(f"Node {source_node} or {target_node} not found in the graph.")
  return graph
def rename_node(node,graph):###############################
  node.relable_nodes(graph,node)
def remove_node(node,graph):
  if node in graph.nodes():
    graph.remove_node(node)
  else:
    print(f"Node {node} not found in the graph.")
  return graph
def print_info(graph):
  print ("name:", graph.name)
  print ("type:", graph.type)
  print ("number of nodes:", graph.number_of_nodes())
  print ("number of edges:", graph.number_of_edges())
  return graph
def move_node(node, graph):################################
  return

def is_tree(graph):
  return print(nx.is_tree(graph))

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
def make_tree(graph):
  return nx.junction_tree(graph)

def find_hamilton_cycles(graph):
    cut_vertices = list(nx.articulation_points(graph))
    cut_edges = list(nx.bridges(graph))
    if not cut_edges and not cut_vertices:
        cycles = list(nx.find_cycle(graph))
        if cycles:
            print("Hamiltonian cycles found:")
            for cycle in cycles:
                print(cycle)
        else:
            print("Your graph does not have any Hamiltonian cycles.")
    else:
        print("Your graph contains cut vertices or cut edges, so it does not have any Hamiltonian cycles.")



# G = create_graph()
G = nx.Graph()
G.add_edges_from([(1, 2), (2, 5), (3, 4), (5, 1),(5,3),(4,2)])
find_hamilton_cycles(G)
plt.figure()
nx.draw(G, with_labels=True, font_weight='bold')
plt.show()
# subax1 = plt.subplot(121)
# nx.draw(G, with_labels=True, font_weight='bold')
# subax2 = plt.subplot(122)
# nx.draw_shell(G, nlist=[range(5, 5), range(1)], with_labels=True, font_weight='bold')
# plt.show()