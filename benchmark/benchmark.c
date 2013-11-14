#include "benchmark.h"
#include "../src/quadtree.h"

static quadtree_t *tree;

void insert_100000_times() {
  int times = 100000, val = 10;
  double x, y;

  start();
  while(times--){
    x = (double) (rand() % 1000);
    y = (double) (rand() % 1000);
    quadtree_insert(tree, x, y, &val);
  }
  stop();
}

void ascent(node_t *node) {
  if (node && node->point) {
    // ok
  }
}

void descent(node_t *node) {
  if (node && node->point) {
    // ok
  }
}

void walking_in_tree_with_100000_points() {
  start();
  quadtree_walk(tree->root, &ascent, &descent);
  stop();
}

int main(){
  b_desc();
  srand(time(NULL));
  tree = quadtree_new(0, 0, 1000, 1000);

  bench(insert_100000_times, 0.12);
  bench(walking_in_tree_with_100000_points, 0.01);

  quadtree_free(tree);
  return b_isok();
}
