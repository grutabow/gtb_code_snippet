

    .section .text.Init

    .global int_irq
    .extern IOT_MQTT_Publish

int_irq:
    LDR R0, =IOT_MQTT_Publish
    BX R0
    
    .section .text.Init1

    .global build_another_qq
    .type build_another_qq,%function
    .extern IOT_MQTT_Publish
build_another_qq:
    CMP r0, r1
    LDR r2, =IOT_MQTT_Publish
    BLXEQ r2
    MOV  PC, LR

    .section .data
    
    .global how_to_watch
how_to_watch:
    .word  0x1234
    
.end
