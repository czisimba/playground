#include <stdio.h>

enum vport_type {
    VP_1 = 1,
    VP_2 = 2,
    VP_4 = 4,
};

struct vport_ops {
    enum vport_type type;
    int (*init)(void);
    void (*exit)(void);
};

int init_vport() {
    printf("init vport success!\n");
    return 0;
}

void exit_vport() {
    printf("exit vport success!\n");
}

int main()
{
    const struct vport_ops v_ops = {
        VP_1,
        init_vport,
        exit_vport,
    };

    v_ops.init();
    v_ops.exit();

    return 0;
}
