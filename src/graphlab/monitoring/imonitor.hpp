


//
// Generic listener interface for monitoring, debugging and profiling.
//

#ifndef GRAPHLAB_IMONITOR_HPP
#define GRAPHLAB_IMONITOR_HPP


#include <graphlab/graph/graph.hpp>
#include <graphlab/tasks/update_task.hpp>
#include <graphlab/scope/iscope.hpp>

namespace graphlab {
  
  // Predecleration 
  template<typename Graph> class iengine;
  
  template<typename Graph>
  class imonitor {    
  public:
    
    typedef Graph graph_type;
    typedef update_task<Graph> update_task_type;
    typedef iscope<Graph> iscope_type;
    typedef iengine<Graph> iengine_type;

    /* Initialization, called by the engine */
    virtual void init(iengine_type* engine) { }
    
    /* Engine calls */
    virtual void engine_task_execute_start(update_task_type task, 
                                           iscope_type* scope, 
                                           size_t cpuid) { }
    
    virtual void engine_task_execute_finished(update_task_type task, 
                                              iscope_type* scope, 
                                              size_t cpuid) { }
    
    virtual void engine_worker_starts(size_t cpuid) { }
    
    virtual void engine_worker_dies(size_t cpuid, int taskcount) { }
    
    
    
    /* Scheduler calls */
    virtual void scheduler_task_added(update_task_type task, double priority) { }
    
    virtual void scheduler_task_promoted(update_task_type task, 
                                         double diffpriority, 
                                         double totalpriority) { }
    
    virtual void scheduler_task_scheduled(update_task_type task, 
                                          double current_max_priority) { }
    
    virtual void scheduler_task_pruned(update_task_type task) { }
    
    /* Application calls */
    virtual void app_set_vertex_value(vertex_id_t vid, double value) { }
    
    /* Called by application to help visualizers to scale values properly */
    virtual void app_set_vertex_value_scale(double min, double max) { }
    
  };
}

#endif

