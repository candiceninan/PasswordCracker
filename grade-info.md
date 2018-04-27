# Grade Information

## Test 1: Compilation

No dead/leftover/unnecessary code should be highlighted here. [1 pts]

```
+ mpicc -g -Wall passwd.c -o passwd
+ test_end
+ return=0
+ [Output Lines: 0]
+ [Time elapsed: 0.10083]
```

## Test 2: Output Limiting

Hash should print only every 1m inversions

```
+ mpirun -n 2 ./passwd 2 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphanum
Starting parallel password cracker.
Number of processes: 2
Coordinator node: silicon
Valid characters: abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 (62)
Target password length: 2
Target hash: 219E0B1F651D744D6B6D254BF97816B2D8CF9260
[0|0] aa -> E0C9035898DD52FC65C41454CEC9C4D2611BFB37
[1|0] Fa -> C850EDC11EEF592324DF76F0D5AF9E7D887EB41D
Operation complete.
Time elapsed: 0.00s
Total passwords hashed: 3844 (798835.88/s)
FAILED to recover password!
+ test_end
+ return=0
+ [Output Lines: 12]
+ [Time elapsed: 0.12044]
```

## Test 3: Password length too short

```
+ timeout 1 ./passwd 0 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphanum
Password must be AT LEAST one character! 
+ test_end
+ return=1
+ [Output Lines: 1]
+ [Time elapsed: 0.0829802]
```

## Test 4: Password hash too short

```
+ timeout 1 ./passwd 5 219E0B1F651D744D6B6D254BF9781 alphanum
Hash length is NOT valid. 
+ test_end
+ return=1
+ [Output Lines: 1]
+ [Time elapsed: 0.0806]
```

## Test 5: Alphanumeric: 6emjb

```
+ timeout 100 mpirun --oversubscribe -n 30 ./passwd 5 219E0B1F651D744D6B6D254BF97816B2D8CF9260 alphanum
Starting parallel password cracker.
Number of processes: 30
Coordinator node: silicon
Valid characters: abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 (62)
Target password length: 5
Target hash: 219E0B1F651D744D6B6D254BF97816B2D8CF9260
[20|0] Oaaaa -> 3EECF384C09E38A70EF2C460DE343EF23E7D4618
[21|0] Qaaaa -> 624BFFEF34652DB4AD74A6255B0C46B3353B9404
[23|0] Uaaaa -> 7F96726332DBA59A406F822D29406E1418E61585
[26|0] 0aaaa -> B973C5D6405DD4252C5F4E0864A761FC3DA7A3D6
[5|0] kaaaa -> D34DA23BF08323D8999F49914332C4E56ECEA63B
[14|0] Caaaa -> F09DF64AF61112C89ECDE84918EBB9C73765A51D
[17|0] Iaaaa -> D2DE204BD14A94D4693CF2D5B98BAC4AB32210EF
[22|0] Saaaa -> 9AD10960F8ADD1972F2429FF1D38A3E437F0ECA8
[24|0] Waaaa -> B4045C8F309D72F754F5B23D04BE86DF558EAFC6
[25|0] Yaaaa -> A263CCBFBAF14A70BD325414CB7A1E52465D9B7A
[27|0] 2aaaa -> 7170A57C17AAB715394378A085DB315A841AE3C8
[28|0] 4aaaa -> AFF5459C9BD1092FE987CD62BB1F0285FA84A263
[29|0] 6aaaa -> 8543683991F0BBFFB9CE9B887B968E733653FEC8
[1|0] caaaa -> 9A19AFC55AD6ABCDE21FC3E58812B5366811463D
[2|0] eaaaa -> 5EB706F345145333631C8DB88196B360EF8FDF3E
[3|0] gaaaa -> 5751CAB481EA9A81C75D256E400346FC6614E612
[6|0] maaaa -> FBD606D1E9E684B2750AC1DE2BCB6417A5E56620
[7|0] oaaaa -> 9D5D663A8C768D92E8EB598D89B1C8ED3B42D98F
[11|0] waaaa -> A5D47C6A61228A9E3218D98011DEB7D1EA772B2E
[12|0] yaaaa -> 57A4E88229DD343D8E4A852C4F66AF003A2D9B05
[13|0] Aaaaa -> 47F4C39137C9CC961E936B3BF12B8E140596ACDB
[15|0] Eaaaa -> 3156614CC00B38AE6475160D8FF2BAB011C6E854
[4|0] iaaaa -> FBA4A187C9AC27FDB2D1E8DB1D7545AA39A3D6A0
[8|0] qaaaa -> DDE2108CD3CA6D942CA42F5B50FBED6B7DCAE72A
[9|0] saaaa -> 0368544A04456C6B4391FD5F2A428A950A27AA3A
[10|0] uaaaa -> 60896C49C07E66EB5CC57F17804FBA83E682CB45
[16|0] Gaaaa -> E7409B425AD43D09D747161AEA60178EACD099C5
[18|0] Kaaaa -> E5299A29EE37EF9E89A7810D05C85A5BF97BBB7E
[19|0] Maaaa -> 2464CA46294C44DA0C5D5CC84C399E31C8DC4681
[0|0] aaaaa -> DF51E37C269AA94D38F93E537BF6E2020B21406C
[22|1000000] Semjc -> 6F349D3AEB5405761F0CF7A363FFD8F4293DDB6E
[8|1000000] qemjc -> AFA1EBBB5C4B74D9CAC266B44099C09CB7C04C14
[1|1000000] cemjc -> 5460155B3D1B42712BC93D9F7900430786F13E70
[13|1000000] Aemjc -> C0B573C411E8372DF01C137B503A21E43FCDE4FD
[18|1000000] Kemjc -> EB99AD8B32EB626CB4C147F4DD328A1177D33ADF
[9|1000000] semjc -> 15B220D9FFBCE9E736D1975EA0DAD3371B120A4A
[23|1000000] Uemjc -> B8606F096303E890F22129D040A77FB6E02BFD48
[15|1000000] Eemjc -> E18634C58B0D6A71A90A6FBE4B1A6CA916A80C10
[16|1000000] Gemjc -> AC59246417973F9E1DCADA86DD4D7F91E630A6D7
[11|1000000] wemjc -> 2D5ED1E80C2423FCF04B2630720A1EEA7796A4FC
[6|1000000] memjc -> 6924BD26E0BF47A6E386485900F6057E241C2DE2
[12|1000000] yemjc -> DAAA474DDC57EAED6E8001A31DDD4858AE07AC5E
[28|1000000] 4emjc -> 79825000CA9B59730DBD50EA8B8C8CB001A785E5
[17|1000000] Iemjc -> 0D2F1EF35560296C038093BA515E378B3D3C953C
[5|1000000] kemjc -> 522CCD5486F233103BFB60800C254291BDE30281
[19|1000000] Memjc -> 97F40A7B17EB57520D3B8A989CE577BB129A043E
[10|1000000] uemjc -> 3A3F4E3F3FECFDD93124C05064630F02E3333F79
[25|1000000] Yemjc -> 59326FF03C9278229E87CF0DD3E52055751A8651
[27|1000000] 2emjc -> 13778AEEC4EDCDD812288A387212F7CFBA87469C
[4|1000000] iemjc -> F5753CC7BE9DFD0F7129847F282D7F00521B308D
[7|1000000] oemjc -> DBDD34F54E8D5B7D0FC25DC23BB8886C3528768A
Operation complete.
Time elapsed: 39.80s
Total passwords hashed: 30014041 (754209.58/s)
Recovered password: 6emjb
+ test_end
+ return=0
+ [Output Lines: 61]
+ [Time elapsed: 40.1862]
```

## Test 6: Numeric: 900000001

```
+ timeout 10 mpirun --oversubscribe -n 10 ./passwd 9 eee65088f52323a4405db87cb40c706accf7ffe5 numeric
Starting parallel password cracker.
Number of processes: 10
Coordinator node: silicon
Valid characters: 0123456789 (10)
Target password length: 9
Target hash: EEE65088F52323A4405DB87CB40C706ACCF7FFE5
[4|0] 400000000 -> 98FB353E16BB87DDA6FE7708A87D5118F5B1DFCD
[6|0] 600000000 -> A0FE7C2170B461B8567E11AD2717C3DB15ED9B29
[8|0] 800000000 -> 2CB7F92DE1350C2F5513D5D84158B1C543AFDC09
[9|0] 900000000 -> 9ECD4D73995CDC57240EE23173D0850811623CAD
[0|0] 000000000 -> 0F58D5A5515F1A8A9D179AA58858B67B2F8A3388
[2|0] 200000000 -> 3B7C909AC677D527D05D39BC3ACA516E2E8891AB
[5|0] 500000000 -> 81CCC8BD8CBB09AA29DFA0432733DCF024608811
[1|0] 100000000 -> B1A65867CC115A8EE517D11F5CAF766E8BCFA0C9
Operation complete.
Time elapsed: 0.00s
Total passwords hashed: 38 (55476.35/s)
Recovered password: 900000001
+ test_end
+ return=0
+ [Output Lines: 18]
+ [Time elapsed: 0.15756]
```

## Test 7: Alpha: Liu (provided test case)

```
+ timeout 10 mpirun --oversubscribe -n 4 ./passwd 4 a3a73b6dfa8f4caedd0349f676ae46b39bdb7fbd alpha
[2|0] Aaaa -> 2E37D6CEAD3C1AC4FFDCDBB97DA3FD4DDDF515CE
Starting parallel password cracker.
Number of processes: 4
Coordinator node: silicon
Valid characters: abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ (52)
Target password length: 4
Target hash: A3A73B6DFA8F4CAEDD0349F676AE46B39BDB7FBD
[0|0] aaaa -> 70C881D4A26984DDCE795F6F71817C9CF4480E79
[1|0] naaa -> 2B28F35E88318776C97DA2B4286AFCBA761BCF11
[3|0] Naaa -> 7E4988A19A29114C6AC6C98C2C4ABA1A51364AA5
[0|1000000] hfQO -> D0E8896122AA9D97B53650326E28962E00718E1E
[1|1000000] ufQO -> E068379F36D0DB57647F85BCBD10996C915BA228
[2|1000000] HfQO -> 6D8FBA5910BF61B2AC826331498D0646145823BE
[3|1000000] UfQO -> 54900C28DA85FA9E068F404D6CF52CE9D08E767D
Operation complete.
Time elapsed: 4.39s
Total passwords hashed: 6794018 (1548193.10/s)
Recovered password: Meow
+ test_end
+ return=0
+ [Output Lines: 18]
+ [Time elapsed: 4.50134]
```

## Test 8: Alphanumeric: Iaaaaaaaaaaemja

```
+ timeout 60 mpirun --oversubscribe -n 25 ./passwd 15 58765A498C1AE6A1518DC9DA54514EA26298D658
[silicon:11741] *** Process received signal ***
[silicon:11741] Signal: Segmentation fault: 11 (11)
[silicon:11741] Signal code: Address not mapped (1)
[silicon:11741] Failing at address: 0x0
[silicon:11741] [ 0] 0   libsystem_platform.dylib            0x00007fff5d271f5a _sigtramp + 26
[silicon:11741] [ 1] 0   ???                                 0x0000ffff00001fa0 0x0 + 281470681751456
[silicon:11741] [ 2] 0   passwd                              0x000000010222959e main + 382
[silicon:11741] [ 3] 0   libdyld.dylib                       0x00007fff5cf63015 start + 1
[silicon:11741] [ 4] 0   ???                                 0x0000000000000003 0x0 + 3
[silicon:11741] *** End of error message ***
[silicon:11740] *** Process received signal ***
[silicon:11740] Signal: Segmentation fault: 11 (11)
[silicon:11740] Signal code: Address not mapped (1)
[silicon:11740] Failing at address: 0x0
[silicon:11740] [ 0] 0   libsystem_platform.dylib            0x00007fff5d271f5a _sigtramp + 26
[silicon:11740] [ 1] 0   ???                                 0x0000ffff00001fa0 0x0 + 281470681751456
[silicon:11740] [ 2] 0   passwd                              0x000000010a78a59e main + 382
[silicon:11740] [ 3] 0   libdyld.dylib                       0x00007fff5cf63015 start + 1
[silicon:11740] [ 4] 0   ???                                 0x0000000000000003 0x0 + 3
[silicon:11740] *** End of error message ***
[silicon:11742] *** Process received signal ***
[silicon:11742] Signal: Segmentation fault: 11 (11)
[silicon:11742] Signal code: Address not mapped (1)
[silicon:11742] Failing at address: 0x0
[silicon:11742] [ 0] 0   libsystem_platform.dylib            0x00007fff5d271f5a _sigtramp + 26
[silicon:11742] [ 1] 0   ???                                 0x0000ffff00001fa0 0x0 + 281470681751456
[silicon:11742] [ 2] 0   passwd                              0x000000010bffc59e main + 382
[silicon:11742] [ 3] 0   libdyld.dylib                       0x00007fff5cf63015 start + 1
[silicon:11742] [ 4] 0   ???                                 0x0000000000000003 0x0 + 3
[silicon:11742] *** End of error message ***
[silicon:11739] *** Process received signal ***
[silicon:11739] Signal: Segmentation fault: 11 (11)
[silicon:11739] Signal code: Address not mapped (1)
[silicon:11739] Failing at address: 0x0
[silicon:11739] [ 0] 0   libsystem_platform.dylib            0x00007fff5d271f5a _sigtramp + 26
[silicon:11739] [ 1] 0   ???                                 0x0000ffff00001fa0 0x0 + 281470681751456
[silicon:11739] [ 2] 0   passwd                              0x000000010891b59e main + 382
[silicon:11739] [ 3] 0   libdyld.dylib                       0x00007fff5cf63015 start + 1
[silicon:11739] [ 4] 0   ???                                 0x0000000000000003 0x0 + 3
[silicon:11739] *** End of error message ***
[silicon:11743] *** Process received signal ***
[silicon:11743] Signal: Segmentation fault: 11 (11)
[silicon:11743] Signal code: Address not mapped (1)
[silicon:11743] Failing at address: 0x0
[silicon:11743] [ 0] 0   libsystem_platform.dylib            0x00007fff5d271f5a _sigtramp + 26
[silicon:11743] [ 1] 0   ???                                 0x0000ffff00001fa0 0x0 + 281470681751456
[silicon:11743] [ 2] [silicon:11746] *** Process received signal ***
[silicon:11746] Signal: Segmentation fault: 11 (11)
[silicon:11746] Signal code: Address not mapped (1)
[silicon:11746] Failing at address: 0x0
[silicon:11746] [ 0] 0   libsystem_platform.dylib            0x00007fff5d271f5a _sigtramp + 26
[silicon:11746] [ 1] 0   ???                                 0x0000ffff00001fa0 0x0 + 281470681751456
[silicon:11746] [ 2] 0   passwd                              0x000000010f46e59e main + 382
[silicon:11746] [ 3] 0   libdyld.dylib                       0x00007fff5cf63015 start + 1
[silicon:11746] [ 4] 0   ???                                 0x0000000000000003 0x0 + 3
[silicon:11746] *** End of error message ***
0   passwd                              0x00000001003b659e main + 382
[silicon:11743] [ 3] 0   libdyld.dylib                       0x00007fff5cf63015 start + 1
[silicon:11743] [ 4] 0   ???                                 0x0000000000000003 0x0 + 3
[silicon:11743] *** End of error message ***
[silicon:11745] *** Process received signal ***
[silicon:11745] Signal: Segmentation fault: 11 (11)
[silicon:11745] Signal code: Address not mapped (1)
[silicon:11745] Failing at address: 0x0
[silicon:11745] [ 0] 0   libsystem_platform.dylib            0x00007fff5d271f5a _sigtramp + 26
[silicon:11745] [ 1] 0   ???                                 0x0000ffff00001fa0 0x0 + 281470681751456
[silicon:11745] [ 2] 0   passwd                              0x0000000109c9259e main + 382
[silicon:11745] [ 3] 0   libdyld.dylib                       0x00007fff5cf63015 start + 1
[silicon:11745] *** End of error message ***
[silicon:11744] *** Process received signal ***
[silicon:11744] Signal: Segmentation fault: 11 (11)
[silicon:11744] Signal code: Address not mapped (1)
[silicon:11744] Failing at address: 0x0
[silicon:11744] [ 0] 0   libsystem_platform.dylib            0x00007fff5d271f5a _sigtramp + 26
[silicon:11744] [ 1] 0   ???                                 0x0000ffff00001fa0 0x0 + 281470681751456
[silicon:11744] [ 2] 0   passwd                              0x00000001027fc59e main + 382
[silicon:11744] [ 3] 0   libdyld.dylib                       0x00007fff5cf63015 start + 1
[silicon:11744] [ 4] 0   ???                                 0x0000000000000003 0x0 + 3
[silicon:11744] *** End of error message ***
-------------------------------------------------------
Primary job  terminated normally, but 1 process returned
a non-zero exit code. Per user-direction, the job has been aborted.
-------------------------------------------------------
[silicon:11759] *** Process received signal ***
[silicon:11759] Signal: Segmentation fault: 11 (11)
[silicon:11759] Signal code: Address not mapped (1)
[silicon:11759] Failing at address: 0x0
[silicon:11759] [ 0] 0   libsystem_platform.dylib            0x00007fff5d271f5a _sigtramp + 26
[silicon:11759] [ 1] 0   ???                                 0x0000000000000000 0x0 + 0
[silicon:11759] [ 2] 0   passwd                              0x000000010ebb559e main + 382
[silicon:11759] [ 3] 0   libdyld.dylib                       0x00007fff5cf63015 start + 1
[silicon:11759] *** End of error message ***
[silicon:11754] *** Process received signal ***
[silicon:11754] Signal: Segmentation fault: 11 (11)
[silicon:11754] Signal code: Address not mapped (1)
[silicon:11754] Failing at address: 0x0
[silicon:11754] [ 0] 0   libsystem_platform.dylib            0x00007fff5d271f5a _sigtramp + 26
[silicon:11754] [ 1] 0   ???                                 0x0000000000000000 0x0 + 0
[silicon:11754] [ 2] 0   passwd                              0x000000010218e59e main + 382
[silicon:11754] [ 3] 0   libdyld.dylib                       0x00007fff5cf63015 start + 1
[silicon:11754] *** End of error message ***
[silicon:11751] *** Process received signal ***
[silicon:11751] Signal: Segmentation fault: 11 (11)
[silicon:11751] Signal code: Address not mapped (1)
[silicon:11751] Failing at address: 0x0
[silicon:11751] [ 0] 0   libsystem_platform.dylib            0x00007fff5d271f5a _sigtramp + 26
[silicon:11751] [ 1] 0   ???                                 0x0000000000000000 0x0 + 0
[silicon:11751] [ 2] 0   passwd                              0x00000001086b259e main + 382
[silicon:11751] [ 3] 0   libdyld.dylib                       0x00007fff5cf63015 start + 1
[silicon:11751] *** End of error message ***
[silicon:11756] *** Process received signal ***
[silicon:11756] Signal: Segmentation fault: 11 (11)
[silicon:11756] Signal code: Address not mapped (1)
[silicon:11756] Failing at address: 0x0
[silicon:11756] [ 0] 0   libsystem_platform.dylib            0x00007fff5d271f5a _sigtramp + 26
[silicon:11756] [ 1] 0   ???                                 0x0000000000000000 0x0 + 0
[silicon:11756] [ 2] 0   passwd                              0x00000001022e459e main + 382
[silicon:11756] [ 3] 0   libdyld.dylib                       0x00007fff5cf63015 start + 1
[silicon:11756] *** End of error message ***
[silicon:11761] *** Process received signal ***
[silicon:11761] Signal: Segmentation fault: 11 (11)
[silicon:11761] Signal code: Address not mapped (1)
[silicon:11761] Failing at address: 0x0
[silicon:11761] [ 0] 0   libsystem_platform.dylib            0x00007fff5d271f5a _sigtramp + 26
[silicon:11761] [ 1] 0   ???                                 0x0000000000000000 0x0 + 0
[silicon:11761] [ 2] 0   passwd                              0x000000010f00059e main + 382
[silicon:11761] [ 3] 0   libdyld.dylib                       0x00007fff5cf63015 start + 1
[silicon:11761] *** End of error message ***
--------------------------------------------------------------------------
mpirun noticed that process rank 7 with PID 0 on node silicon exited on signal 11 (Segmentation fault: 11).
--------------------------------------------------------------------------
+ test_end
+ return=139
+ [Output Lines: 131]
+ [Time elapsed: 0.28297]
```

## Test 9: Invalid password, too many processes

```
+ timeout 5 mpirun --oversubscribe -n 20 ./passwd 3 58765A498C1AE6A1518DC9DA54514EA26298D658 numeric
Starting parallel password cracker.
Number of processes: 20
Coordinator node: silicon
Valid characters: 0123456789 (10)
Target password length: 3
Target hash: 58765A498C1AE6A1518DC9DA54514EA26298D658
[19|0] 000 -> 8AEFB06C426E07A0A671A1E2488B4858D694A730
Operation complete.
Time elapsed: 0.01s
Total passwords hashed: 1000 (112980.93/s)
FAILED to recover password!
+ test_end
+ return=0
+ [Output Lines: 11]
+ [Time elapsed: 0.281]
```


## Deductions

* (Test 8): Password not recovered [-1]

Awesome work!!

